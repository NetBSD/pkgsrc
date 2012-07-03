$NetBSD: patch-libxipc_xrl__error.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxipc/xrl_error.hh.orig	2009-01-05 18:30:56.000000000 +0000
+++ libxipc/xrl_error.hh
@@ -27,7 +27,7 @@
 #include "libxorp/c_format.hh"
 
 
-struct XrlErrlet;
+class XrlErrlet;
 
 enum XrlErrorCode {
     OKAY		  = 100,
