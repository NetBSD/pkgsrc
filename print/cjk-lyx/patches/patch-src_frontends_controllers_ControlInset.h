$NetBSD: patch-src_frontends_controllers_ControlInset.h,v 1.1 2011/12/29 16:36:37 joerg Exp $

--- src/frontends/controllers/ControlInset.h.orig	2011-12-29 13:27:08.000000000 +0000
+++ src/frontends/controllers/ControlInset.h
@@ -105,5 +105,6 @@ private:
 
 };
 
+#include "ControlInset.tmpl"
 
 #endif // CONTROLINSET_H
