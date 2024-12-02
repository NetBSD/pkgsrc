$NetBSD: patch-lib_gvpr_compile.h,v 1.1 2024/12/02 16:02:30 jperkin Exp $

Avoid lock_t.

--- lib/gvpr/compile.h.orig	2024-12-02 15:58:56.601986844 +0000
+++ lib/gvpr/compile.h
@@ -38,11 +38,11 @@ extern "C" {
 typedef struct {
   bool locked: 1; ///< is the lock currently taken?
   bool zombie: 1; ///< was a deletion request recorded while locked?
-} lock_t;
+} gvprlock_t;
 
     typedef struct {
 	Agrec_t h;
-	lock_t lock;
+	gvprlock_t lock;
     } gval_t;
 
     typedef struct {
