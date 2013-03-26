$NetBSD: patch-kopete_protocols_groupwise_libgroupwise_qcatlshandler.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- kopete/protocols/groupwise/libgroupwise/qcatlshandler.h.orig	2013-03-26 19:57:51.000000000 +0000
+++ kopete/protocols/groupwise/libgroupwise/qcatlshandler.h
@@ -23,7 +23,9 @@
 //#include <qtimer.h>
 #include "tlshandler.h"
 
-class QCA::TLS;
+namespace QCA {
+class TLS;
+}
 
 class QCATLSHandler : public TLSHandler
 {
