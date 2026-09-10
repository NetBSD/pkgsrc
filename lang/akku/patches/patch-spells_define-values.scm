$NetBSD: patch-spells_define-values.scm,v 1.1 2026/09/10 00:45:14 ktnb Exp $

Fix an issue with define-values generating unbound variables
when compiled with Guile >= 3.0.11

https://aur.archlinux.org/cgit/aur.git/tree/define-values.patch

--- spells/define-values.scm.orig	2021-02-06 19:18:57.000000000 +0000
+++ spells/define-values.scm
@@ -35,21 +35,15 @@
          (with-syntax (((dummy) (generate-temporaries '(dummy))))
            (syntax
             (define dummy (begin exp ... 'dummy)))))
-	((_ (id ...) exp0 exp ...)
-	 ;; Mutable-ids are needed so that ids defined by
-	 ;; define-values can be exported from a library (mutated
-	 ;; variables cannot be exported).  This fix is due to Andre
-	 ;; van Tonder.
-	 (with-syntax (((mutable-id ...) (generate-temporaries (syntax (id ...))))
-		       ((result ...)     (generate-temporaries (syntax (id ...))))
+        ((_ (id ...) exp0 exp ...)
+         (with-syntax (((result ...)     (generate-temporaries (syntax (id ...))))
                        ((dummy)          (generate-temporaries '(dummy))))
-	   (syntax
-	    (begin
-	      (define mutable-id) ...
-	      (define dummy
-		(call-with-values
-                    (lambda () exp0 exp ...)
-		  (lambda (result ...)
-		    (set! mutable-id result) ...
-                    'dummy)))
-	      (define id mutable-id) ...))))))))
+           (syntax
+            (begin
+              (define id) ...
+              (define dummy
+                (call-with-values
+                 (lambda () exp0 exp ...)
+                 (lambda (result ...)
+                   (set! id result) ...
+                   'dummy)))))))))))
