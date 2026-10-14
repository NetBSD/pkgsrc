$NetBSD: patch-build-aux_guile-baux_common.scm,v 1.1 2026/10/14 23:58:41 gdt Exp $

--- build-aux/guile-baux/common.scm.orig	2026-10-14 23:54:45.829163835 +0000
+++ build-aux/guile-baux/common.scm
@@ -19,7 +19,7 @@
 
 (define-module (guile-baux common)
   #:export (fs fso fse die check-hv qop<-args)
-  #:autoload (ice-9 getopt-long) (getopt-long)
+  #:autoload (ice-9 getopt-long) (getopt-long option-ref)
   #:autoload (ice-9 documentation) (file-commentary)
   #:use-module ((srfi srfi-13) #:select (string-trim-both)))
 
