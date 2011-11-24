$NetBSD: patch-gsmlib_gsm__me__ta.cc,v 1.1 2011/11/24 14:17:06 joerg Exp $

--- gsmlib/gsm_me_ta.cc.orig	2002-10-22 20:48:39.000000000 +0000
+++ gsmlib/gsm_me_ta.cc
@@ -18,6 +18,7 @@
 #include <gsmlib/gsm_me_ta.h>
 #include <gsmlib/gsm_parser.h>
 #include <gsmlib/gsm_sysdep.h>
+#include <stdlib.h>
 
 using namespace std;
 using namespace gsmlib;
