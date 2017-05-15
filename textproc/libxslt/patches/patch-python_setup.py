$NetBSD: patch-python_setup.py,v 1.1 2017/05/15 18:07:40 dholland Exp $

Fix rpath handling. Needs to link to libxml2mod.so explicitly.

--- python/setup.py.orig	2017-05-15 18:02:13.012917947 +0000
+++ python/setup.py
@@ -53,7 +53,7 @@ if xml_includes == "":
 iconv_includes="@LIBICONVDIR@/include"
 
 # those are added in the linker search path for libraries
-libdirs = ["@LIBXML2DIR@/lib"]
+libdirs = ["@LIBXML2DIR@/lib", "@PYSHLIBDIR@"]
 
 xml_files = ["libxml2-api.xml", "libxml2-python-api.xml",
              "libxml.c", "libxml.py", "libxml_wrap.h", "types.c",
@@ -132,7 +132,7 @@ descr = "libxml2 package"
 modules = []
 c_files = []
 includes= [xml_includes, iconv_includes]
-libs    = [] + platformLibs
+libs    = ["xml2mod"] + platformLibs
 macros  = []
 if with_threads:
     macros.append(('_REENTRANT','1'))
@@ -161,7 +161,8 @@ if with_xslt == 1:
 extens=[]
 if with_xslt == 1:
     extens.append(Extension('libxsltmod', xslt_c_files, include_dirs=includes,
-			    library_dirs=libdirs, 
+			    library_dirs=libdirs,
+			    runtime_library_dirs=libdirs,
                             libraries=libs, define_macros=macros))
 
 if missing("MANIFEST"):
