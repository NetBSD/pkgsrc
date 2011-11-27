$NetBSD: patch-vmips.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- vmips.cc.orig	2011-11-27 02:51:01.000000000 +0000
+++ vmips.cc
@@ -50,6 +50,7 @@ with VMIPS; if not, write to the Free So
 #include <cassert>
 #include <csignal>
 #include <cstdarg>
+#include <cstring>
 #include <string>
 #include <exception>
 
