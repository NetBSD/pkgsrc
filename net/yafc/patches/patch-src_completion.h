$NetBSD: patch-src_completion.h,v 1.1 2014/04/17 20:27:33 joerg Exp $

--- src/completion.h.orig	2001-12-11 11:21:52.000000000 +0000
+++ src/completion.h
@@ -14,7 +14,7 @@
 #ifndef _COMPLETION_H_INCLUDED
 #define _COMPLETION_H_INCLUDED
 
-char **the_complete_function(char *text, int start, int end);
-char *no_completion_function(char *text, int state);
+char **the_complete_function(const char *text, int start, int end);
+char *no_completion_function(const char *text, int state);
 
 #endif
