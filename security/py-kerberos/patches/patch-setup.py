$NetBSD: patch-setup.py,v 1.1 2016/06/09 02:06:18 markd Exp $

Support heimdal

--- setup.py.orig	2016-01-25 17:55:44.000000000 +0000
+++ setup.py
@@ -80,6 +80,8 @@ extra_link_args = getoutput("krb5-config
 
 extra_compile_args = getoutput("krb5-config --cflags gssapi").split()

+if getoutput("krb5-config --version").find("heimdal") != -1:
+    extra_compile_args.append("-DHEIMDAL")
 
 #
 # Set up Extension modules that need to be built
