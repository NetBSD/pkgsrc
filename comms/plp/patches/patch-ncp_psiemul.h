$NetBSD: patch-ncp_psiemul.h,v 1.1 2011/12/19 13:44:07 wiz Exp $

Update for C++ changes.

--- ncp/psiemul.h.orig	1999-04-12 21:16:59.000000000 +0000
+++ ncp/psiemul.h
@@ -1,6 +1,8 @@
 #ifndef _pisemul_h_
 #define _pisemul_h_
 
+#include <iostream>
+using namespace std;
 #include "bool.h"
 
 // The following code does NOT emulate a psion, but it persists "conversations"
