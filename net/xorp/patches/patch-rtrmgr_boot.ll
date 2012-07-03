$NetBSD: patch-rtrmgr_boot.ll,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rtrmgr/boot.ll.orig	2012-07-03 16:26:58.000000000 +0000
+++ rtrmgr/boot.ll
@@ -24,6 +24,7 @@
 	bool arith_op_allowed;
 %option noyywrap
 %option nounput
+%option noinput
 %option never-interactive
 %x comment
 %x string
