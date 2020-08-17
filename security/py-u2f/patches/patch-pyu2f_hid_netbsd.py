$NetBSD: patch-pyu2f_hid_netbsd.py,v 1.1 2020/08/17 20:57:44 riastradh Exp $

Add NetBSD support.

--- pyu2f/hid/netbsd.py.orig	2020-08-17 20:43:03.167593821 +0000
+++ pyu2f/hid/netbsd.py
@@ -0,0 +1,114 @@
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
+import sys
+
+from fcntl import ioctl
+
+from pyu2f.hid import base
+from pyu2f.hid import linux
+
+
+# struct usb_ctl_report_desc {
+# 	int		ucrd_size;
+# 	unsigned char	ucrd_data[1024];
+# };
+
+SIZEOF_USB_CTL_REPORT_DESC = 4 + 1024
+USB_GET_REPORT_DESC = 0x44045515 # _IOR('U', 21, struct usb_ctl_report_desc)
+
+SIZEOF_USB_DEVICE_INFO = 1268
+USB_DEVICE_INFO_PRODUCT = 1168
+USB_DEVICE_INFO_VENDOR = 1170
+USB_GET_DEVICE_INFO = 0x44f45570 # _IOR('U', 112, struct usb_device_info)
+
+USB_HID_SET_RAW = 0x80046802 # _IOW('h', 2, int)
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
+        devinfo = bytearray([0] * SIZEOF_USB_DEVICE_INFO)
+        ioctl(fd, USB_GET_DEVICE_INFO, devinfo, True)
+        vendor = devinfo[USB_DEVICE_INFO_VENDOR:USB_DEVICE_INFO_VENDOR + 2]
+        product = devinfo[USB_DEVICE_INFO_PRODUCT:USB_DEVICE_INFO_PRODUCT + 2]
+        descbuf = bytearray([0] * SIZEOF_USB_CTL_REPORT_DESC)
+        ioctl(fd, USB_GET_REPORT_DESC, descbuf, True)
+        descsize = struct.unpack('@i', descbuf[0:4])[0]
+        descdata = descbuf[4:4 + descsize]
+        desc = base.DeviceDescriptor()
+        desc.path = path
+        desc.vendor_id = struct.unpack('@H', vendor)[0]
+        desc.product_id = struct.unpack('@H', product)[0]
+        linux.ParseReportDescriptor(descdata, desc)
+        if desc.usage_page != FIDO_USAGE_PAGE:
+            raise Exception('usage page != fido')
+        if desc.usage != FIDO_USAGE_U2FHID:
+            raise Exception('fido usage != u2fhid')
+        ioctl(fd, USB_HID_SET_RAW, struct.pack('@i', 1))
+        ping = bytearray([0] * 64)
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
