$NetBSD: patch-python_setup.py,v 1.1 2017/10/31 13:15:44 fhajny Exp $

Trust pkgsrc to know which iconv to use.
It will be either in the buildlink directory, or in the compiler's
default search path.

--- python/setup.py.orig	2014-10-16 07:35:21.000000000 +0000
+++ python/setup.py
@@ -56,11 +56,7 @@ else:
 # - iconv.h
 # - libxslt/xsltconfig.h
 includes_dir = [
-"/usr/include",
-"/usr/local/include",
-"/opt/include",
-os.path.join(ROOT,'include'),
-HOME
+os.path.join(ROOT,'include')
 ];
 
 xml_includes=""
@@ -73,11 +69,7 @@ if xml_includes == "":
     print("failed to find headers for libxml2: update includes_dir")
     sys.exit(1)
 
-iconv_includes=""
-for dir in includes_dir:
-    if not missing(dir + "/iconv.h"):
-        iconv_includes=dir
-        break;
+iconv_includes=os.path.join(ROOT,'include')
 
 if iconv_includes == "":
     print("failed to find headers for libiconv: update includes_dir")
