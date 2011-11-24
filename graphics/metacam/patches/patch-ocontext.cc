$NetBSD: patch-ocontext.cc,v 1.1 2011/11/24 13:59:50 joerg Exp $

--- ocontext.cc.orig	2011-11-24 02:21:02.000000000 +0000
+++ ocontext.cc
@@ -25,6 +25,8 @@ static const char *rcsid __attribute__((
 #include "odrivers.h"
 
 #include <ctype.h>
+#include <cstdlib>
+#include <cstring>
 
 OutputContext::~OutputContext()
 {
