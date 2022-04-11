$NetBSD: patch-node__modules_@npmcli_config_lib_index.js,v 1.1 2022/04/11 18:50:31 adam Exp $

If both PREFIX and DESTDIR are defined, combine for UNIX best practice.

--- node_modules/@npmcli/config/lib/index.js.orig	2020-11-03 09:56:58.000000000 +0000
+++ node_modules/@npmcli/config/lib/index.js
@@ -291,6 +291,9 @@ class Config {
 
     if (this.env.PREFIX) {
       this.globalPrefix = this.env.PREFIX
+      if (this.env.DESTDIR) {
+        this.globalPrefix = join(this.env.DESTDIR, this.globalPrefix)
+      }
     } else if (this.platform === 'win32') {
     // c:\node\node.exe --> prefix=c:\node\
       this.globalPrefix = dirname(this.execPath)
