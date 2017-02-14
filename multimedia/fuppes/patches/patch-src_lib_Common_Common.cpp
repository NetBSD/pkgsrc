$NetBSD: patch-src_lib_Common_Common.cpp,v 1.2 2017/02/14 21:25:50 joerg Exp $

--- src/lib/Common/Common.cpp.orig	2009-12-20 20:26:29.000000000 +0000
+++ src/lib/Common/Common.cpp
@@ -38,6 +38,7 @@
 
 #ifndef WIN32
 #include <dirent.h>
+#include <unistd.h>
 #endif
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -466,7 +467,7 @@ std::string ToUTF8(std::string p_sValue,
 		icv = iconv_open("UTF-8", p_sEncoding.c_str());
 	}
 	
-  if(icv < 0)  
+  if(icv == (iconv_t)-1)  
     return p_sValue;  
   
   size_t nInbytes  = p_sValue.length(); 
