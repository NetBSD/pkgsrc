$NetBSD: patch-fido2___pyu2f_netbsd.py,v 1.2 2020/12/13 07:20:57 riastradh Exp $

Add NetBSD support.

--- fido2/_pyu2f/netbsd.py.orig	2020-12-13 07:06:29.870329750 +0000
+++ fido2/_pyu2f/netbsd.py
@@ -0,0 +1,151 @@
+# Copyright 2016 Google Inc. All Rights Reserved.
+#
+# Licensed under the Apache License, Version 2.0 (the "License");
+# you may not use this file except in compliance with the License.
+# You may obtain a copy of the License at
+#
+#    http://www.apache.org/licenses/LICENSE-2.0
+#
+# Unless required by applicable law or agreed to in writing, software
+# distributed under the License is distributed on an "AS IS" BASIS,
+# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+# See the License for the specific language governing permissions and
+# limitations under the License.
+
+"""Implements raw HID interface on NetBSD."""
+
+from __future__ import absolute_import
+
+import errno
+import os
+import select
+import struct
+
+from ctypes import Structure
+from ctypes import c_char
+from ctypes import c_int
+from ctypes import c_ubyte
+from ctypes import c_uint16
+from ctypes import c_uint32
+from ctypes import c_uint8
+from ctypes import sizeof
+from fcntl import ioctl
+
+from . import base
+from . import linux
+
+
+USB_MAX_DEVNAMELEN = 16
+USB_MAX_DEVNAMES = 4
+USB_MAX_STRING_LEN = 128
+USB_MAX_ENCODED_STRING_LEN = USB_MAX_STRING_LEN * 3
+
+
+class usb_ctl_report_desc(Structure):
+    _fields_ = [
+        ('ucrd_size', c_int),
+        ('ucrd_data', c_ubyte * 1024),
+    ]
+
+
+class usb_device_info(Structure):
+    _fields_ = [
+        ('udi_bus', c_uint8),
+        ('udi_addr', c_uint8),
+        ('udi_pad0', c_uint8 * 2),
+        ('udi_cookie', c_uint32),
+        ('udi_product', c_char * USB_MAX_ENCODED_STRING_LEN),
+        ('udi_vendor', c_char * USB_MAX_ENCODED_STRING_LEN),
+        ('udi_release', c_char * 8),
+        ('udi_serial', c_char * USB_MAX_ENCODED_STRING_LEN),
+        ('udi_productNo', c_uint16),
+        ('udi_vendorNo', c_uint16),
+        ('udi_releaseNo', c_uint16),
+        ('udi_class', c_uint8),
+        ('udi_subclass', c_uint8),
+        ('udi_protocol', c_uint8),
+        ('udi_config', c_uint8),
+        ('udi_speed', c_uint8),
+        ('udi_pad1', c_uint8),
+        ('udi_power', c_int),
+        ('udi_nports', c_int),
+        ('udi_devnames', c_char * USB_MAX_DEVNAMES * USB_MAX_DEVNAMELEN),
+        ('udi_ports', c_uint8 * 16),
+    ]
+
+
+USB_GET_DEVICE_INFO = 0x44f45570  # _IOR('U', 112, struct usb_device_info)
+USB_GET_REPORT_DESC = 0x44045515  # _IOR('U', 21, struct usb_ctl_report_desc)
+USB_HID_SET_RAW = 0x80046802      # _IOW('h', 2, int)
+
+
+FIDO_USAGE_PAGE = 0xf1d0
+FIDO_USAGE_U2FHID = 0x01
+
+
+class NetBSDHidDevice(linux.LinuxHidDevice):
+    """Implementation of HID device for NetBSD.
+    """
+
+    @classmethod
+    def _setup(cls, fd, path):
+        devinfobuf = bytearray(sizeof(usb_device_info))
+        ioctl(fd, USB_GET_DEVICE_INFO, devinfobuf, True)
+        devinfo = usb_device_info.from_buffer(devinfobuf)
+        ucrdbuf = bytearray(sizeof(usb_ctl_report_desc))
+        ioctl(fd, USB_GET_REPORT_DESC, ucrdbuf, True)
+        ucrd = usb_ctl_report_desc.from_buffer(ucrdbuf)
+        descdata = bytearray(ucrd.ucrd_data[:ucrd.ucrd_size])
+        desc = base.DeviceDescriptor()
+        desc.path = path
+        desc.vendor_id = devinfo.udi_vendorNo
+        desc.vendor_string = devinfo.udi_vendor.decode('utf-8')
+        desc.product_id = devinfo.udi_productNo
+        desc.product_string = devinfo.udi_product.decode('utf-8')
+        desc.serial_number = devinfo.udi_serial.decode('utf-8')
+        linux.ParseReportDescriptor(descdata, desc)
+        if desc.usage_page != FIDO_USAGE_PAGE:
+            raise Exception('usage page != fido')
+        if desc.usage != FIDO_USAGE_U2FHID:
+            raise Exception('fido usage != u2fhid')
+        ioctl(fd, USB_HID_SET_RAW, struct.pack('@i', 1))
+        ping = bytearray(64)
+        ping[0:7] = bytearray([0xff,0xff,0xff,0xff,0x81,0,1])
+        for i in range(10):
+            os.write(fd, ping)
+            poll = select.poll()
+            poll.register(fd, select.POLLIN)
+            if poll.poll(100):
+                os.read(fd, 64 + 1)
+                break
+        else:
+            raise Exception('u2f ping timeout')
+        return desc
+
+    @classmethod
+    def Enumerate(cls):
+        for i in range(100):
+            path = '/dev/uhid{}'.format(i)
+            fd = None
+            try:
+                fd = os.open(path, os.O_RDWR|os.O_CLOEXEC)
+                desc = cls._setup(fd, path)
+            except OSError as e:
+                if e.errno == errno.ENOENT:
+                    break
+                continue
+            finally:
+                if fd is not None:
+                    os.close(fd)
+            yield desc.ToPublicDict()
+
+    def __init__(self, path):
+        base.HidDevice.__init__(self, path)
+        self.dev = os.open(path, os.O_RDWR)
+        self.desc = self._setup(self.dev, path)
+
+    def __del__(self):
+        os.close(self.dev)
+
+    def Write(self, packet):
+        os.write(self.dev, bytearray(packet))
