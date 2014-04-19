$NetBSD: patch-plug-ins_icc__examin_icc__examin_icc__thread__daten.cpp,v 1.1 2014/04/19 15:00:09 joerg Exp $

--- plug-ins/icc_examin/icc_examin/icc_thread_daten.cpp.orig	2014-04-19 12:19:41.000000000 +0000
+++ plug-ins/icc_examin/icc_examin/icc_thread_daten.cpp
@@ -31,6 +31,7 @@
 
 #include "icc_thread_daten.h"
 #include "threads.h"
+#include <inttypes.h>
 
 void
 icc_examin_ns::ThreadDaten::frei(int freigeben)
