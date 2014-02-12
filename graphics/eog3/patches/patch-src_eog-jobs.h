$NetBSD: patch-src_eog-jobs.h,v 1.1 2014/02/12 02:05:36 prlw1 Exp $

Prevent redeclaration of typedef 'EogJob'.
https://bugzilla.gnome.org/show_bug.cgi?id=712354
commit aae3be0031991749d60631080867c403a7fd7348

--- src/eog-jobs.h.orig	2013-07-13 14:19:19.000000000 +0000
+++ src/eog-jobs.h
@@ -100,7 +100,11 @@ G_BEGIN_DECLS
 typedef struct _EogURIConverter EogURIConverter;
 #endif
 
+#ifndef __EOG_JOB_DECLR__
+#define __EOG_JOB_DECLR__
 typedef struct _EogJob               EogJob;
+#endif
+
 typedef struct _EogJobClass          EogJobClass;
 
 typedef struct _EogJobCopy           EogJobCopy;
