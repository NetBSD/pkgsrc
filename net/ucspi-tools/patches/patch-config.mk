$NetBSD: patch-config.mk,v 1.1 2020/11/30 12:41:41 nia Exp $

Honor CFLAGS from pkgsrc.

--- config.mk.orig	2016-09-21 22:05:29.000000000 +0000
+++ config.mk
@@ -8,4 +8,4 @@ VERSION = 1.5
 
 # compiler
 CC	    = cc
-CFLAGS	    = -std=c99 -pedantic -Wall -Wextra -g
+CFLAGS	   += -std=c99 -pedantic -Wall -Wextra
