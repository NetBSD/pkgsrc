$NetBSD: patch-src_authenticators_pam_OW__PAMAuthentication.cpp,v 1.1 2013/05/23 14:58:09 joerg Exp $

--- src/authenticators/pam/OW_PAMAuthentication.cpp.orig	2013-05-23 13:20:37.000000000 +0000
+++ src/authenticators/pam/OW_PAMAuthentication.cpp
@@ -39,7 +39,8 @@
 #include "OW_AuthenticatorIFC.hpp"
 #include "OW_Array.hpp"
 
-#include <string.h>
+#include <cstdlib>
+#include <cstring>
 
 #ifdef OW_GNU_LINUX
 	#ifdef OW_HAVE_PWD_H
