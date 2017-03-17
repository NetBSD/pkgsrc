$NetBSD: patch-radicale_config.py,v 1.1 2017/03/17 16:56:47 sborrill Exp $

Add support for strip_domain

--- radicale/config.py.orig	2017-03-17 16:04:36.000000000 +0000
+++ radicale/config.py	2017-03-17 16:05:03.000000000 +0000
@@ -76,7 +76,8 @@
         "courier_socket": "",
         "http_url": "",
         "http_user_parameter": "",
-        "http_password_parameter": ""},
+        "http_password_parameter": "",
+        "strip_domain": "False"},
     "git": {
         "committer": "Radicale <radicale@example.com>"},
     "rights": {
