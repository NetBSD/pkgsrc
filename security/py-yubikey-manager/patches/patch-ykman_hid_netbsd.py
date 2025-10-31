$NetBSD: patch-ykman_hid_netbsd.py,v 1.1 2025/10/31 14:56:39 ryoon Exp $

* For NetBSD. Copied from freebsd.py.

--- ykman/hid/netbsd.py.orig	2025-10-31 07:41:33.798174909 +0000
+++ ykman/hid/netbsd.py
@@ -0,0 +1,188 @@
+# Original work Copyright 2016 Google Inc. All Rights Reserved.
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
+#
+# Modified work Copyright 2022 Michael Gmelin. All Rights Reserved.
+# This file, with modifications, is licensed under the above Apache License.
+#
+# Modified work Copyright 2022 Yubico AB. All Rights Reserved.
+# This file, with modifications, is licensed under the above Apache License.
+
+# NetBSD HID driver using uhid(4).
+#
+
+import ctypes
+import fcntl
+import glob
+import logging
+import os
+import re
+import struct
+import sys
+from ctypes.util import find_library
+
+from yubikit.core.otp import OtpConnection
+
+from .base import USAGE_OTP, YUBICO_VID, OtpYubiKeyDevice
+
+# Don't typecheck this file on Windows
+assert sys.platform != "win32"  # noqa: S101
+
+logger = logging.getLogger(__name__)
+
+devdir = "/dev/"
+
+# /usr/include/dev/usb/usb_ioctl.h
+USB_GET_REPORT = 0xC0205517
+USB_SET_REPORT = 0x80205518
+USB_GET_REPORT_DESC = 0xC0205515
+
+# For UhidConnection
+libc = ctypes.CDLL(find_library("c"))
+
+
+class usb_gen_descriptor(ctypes.Structure):
+    _fields_ = [
+        (
+            "ugd_data",
+            ctypes.c_void_p,
+        ),
+        ("ugd_lang_id", ctypes.c_uint16),
+        ("ugd_maxlen", ctypes.c_uint16),
+        ("ugd_actlen", ctypes.c_uint16),
+        ("ugd_offset", ctypes.c_uint16),
+        ("ugd_config_index", ctypes.c_uint8),
+        ("ugd_string_index", ctypes.c_uint8),
+        ("ugd_iface_index", ctypes.c_uint8),
+        ("ugd_altif_index", ctypes.c_uint8),
+        ("ugd_endpt_index", ctypes.c_uint8),
+        ("ugd_report_type", ctypes.c_uint8),
+        ("reserved", ctypes.c_uint8 * 8),
+    ]
+
+
+class UhidConnection(OtpConnection):
+    """
+    uhid(4) is NetBSD's USB hid access driver
+    """
+
+    def __init__(self, path):
+        self.fd = os.open(path, os.O_RDWR)
+
+    def close(self):
+        os.close(self.fd)
+
+    def receive(self):
+        buf = ctypes.create_string_buffer(9)
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(buf),
+            ugd_maxlen=ctypes.sizeof(buf),
+            ugd_report_type=3,
+        )
+        ret = libc.ioctl(self.fd, USB_GET_REPORT, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed: " + str(ret))
+
+        return buf.raw[:-1]
+
+    def send(self, data):
+        buf = ctypes.create_string_buffer(8)
+        for i in range(0, len(data)):
+            buf[i] = data[i]
+
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(buf),
+            ugd_maxlen=len(buf),
+            ugd_report_type=0x3,
+        )
+        ret = libc.ioctl(self.fd, USB_SET_REPORT, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed: " + str(ret))
+
+    @staticmethod
+    def get_usage(dev):
+        c_data = ctypes.create_string_buffer(4096)
+        desc = usb_gen_descriptor(
+            ugd_data=ctypes.addressof(c_data),
+            ugd_maxlen=ctypes.sizeof(c_data),
+            ugd_report_type=3,
+        )
+        ret = libc.ioctl(dev, USB_GET_REPORT_DESC, ctypes.pointer(desc))
+        if ret != 0:
+            raise ValueError("ioctl failed")
+
+        REPORT_DESCRIPTOR_KEY_MASK = 0xFC
+        SIZE_MASK = ~REPORT_DESCRIPTOR_KEY_MASK
+        USAGE_PAGE = 0x04
+        USAGE = 0x08
+
+        data = c_data.raw
+        usage, usage_page = (None, None)
+        while data and not (usage and usage_page):
+            head, data = struct.unpack_from(">B", data)[0], data[1:]
+            key, size = REPORT_DESCRIPTOR_KEY_MASK & head, SIZE_MASK & head
+            value = struct.unpack_from("<I", data[:size].ljust(4, b"\0"))[0]
+            data = data[size:]
+            if key == USAGE_PAGE and not usage_page:
+                usage_page = value
+            elif key == USAGE and not usage:
+                usage = value
+
+        return (usage_page, usage)
+
+    @staticmethod
+    def get_info(index):
+        vendor_re = re.compile("vendor=(0x[0-9a-fA-F]+)")
+        product_re = re.compile("product=(0x[0-9a-fA-F]+)")
+        sernum_re = re.compile('sernum="([^"]+)')
+
+        pnpinfo = ("dev.uhid." + index + ".%pnpinfo").encode()
+
+        ovalue = ctypes.create_string_buffer(1024)
+        olen = ctypes.c_size_t(ctypes.sizeof(ovalue))
+        key = ctypes.c_char_p(pnpinfo)
+        retval = libc.sysctlbyname(key, ovalue, ctypes.byref(olen), None, None)
+        if retval != 0:
+            raise IOError("sysctlbyname failed")
+
+        value = ovalue.value[: olen.value].decode()
+        m = vendor_re.search(value)
+        vid = int(m.group(1), 16) if m else None
+        m = product_re.search(value)
+        pid = int(m.group(1), 16) if m else None
+        m = sernum_re.search(value)
+        serial = m.group(1) if m else None
+        return (vid, pid, serial)
+
+    @staticmethod
+    def list_devices():
+        devices = []
+        for uhid in glob.glob(devdir + "uhid?*"):
+            index = uhid[len(devdir) + len("uhid") :]
+            if not index.isdigit():
+                continue
+
+            try:
+                (vid, pid, serial) = UhidConnection.get_info(index)
+                if vid == YUBICO_VID:
+                    with open(uhid, "rb") as f:
+                        if UhidConnection.get_usage(f.fileno()) == USAGE_OTP:
+                            devices.append(OtpYubiKeyDevice(uhid, pid, UhidConnection))
+            except Exception as e:
+                logger.debug("Failed opening HID device", exc_info=e)
+                continue
+        return devices
+
+
+def list_devices():
+    return UhidConnection.list_devices()
