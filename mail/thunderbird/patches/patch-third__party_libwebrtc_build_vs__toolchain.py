$NetBSD: patch-third__party_libwebrtc_build_vs__toolchain.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/libwebrtc/build/vs_toolchain.py.orig	2024-10-11 13:43:08.737671418 +0000
+++ third_party/libwebrtc/build/vs_toolchain.py
@@ -9,7 +9,6 @@ import collections
 import glob
 import json
 import os
-import pipes
 import platform
 import re
 import shutil
