$NetBSD: patch-Tcl2.cc,v 1.1 2014/02/01 08:00:06 markd Exp $

Build with tcl8.6

--- Tcl2.cc.orig	2005-09-01 01:54:05.000000000 +0000
+++ Tcl2.cc
@@ -88,7 +88,7 @@ void Tcl::resultf(const char* fmt, ...)
 	va_list ap;
 	va_start(ap, fmt);
 	vsprintf(bp_, fmt, ap);
-	tcl_->result = bp_;
+	Tcl_SetResult(tcl_, (char *)bp_, NULL);
 }
 
 void Tcl::add_errorf(const char* fmt, ...)
