$NetBSD: patch-am,v 1.1 2011/11/22 10:54:15 marino Exp $

--- akode/plugins/mpc_decoder/mppdec/synth_filter.cpp.orig	2004-11-04 23:13:31.000000000 +0000
+++ akode/plugins/mpc_decoder/mppdec/synth_filter.cpp
@@ -1,6 +1,8 @@
 #include "stdafx.h"
 
+#if !defined(__DragonFly__)
 typedef int ptrdiff_t;
+#endif
 
 
 /* C O N S T A N T S */
