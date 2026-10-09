$NetBSD: patch-src_gerbil_expander_root.ss,v 1.1 2026/10/09 14:31:31 ktnb Exp $

Don't get stuck here because of an unsupported sys-type

--- src/gerbil/expander/root.ss.orig	2026-10-06 16:02:10.936771515 +0000
+++ src/gerbil/expander/root.ss
@@ -237,7 +237,8 @@ namespace: gx
         ((bsd-variant sys-type)
          => (lambda (sys-prefix)
               (core-bind-feature! (string->symbol "bsd") #f 0 self)
-              (core-bind-feature! (string->symbol sys-prefix) #f 0 self)))))
+              (unless (eq? (string->symbol sys-prefix) sys-type)
+                (core-bind-feature! (string->symbol sys-prefix) #f 0 self))))))
       (else (void)))
     (when (gerbil-runtime-smp?)
       (core-bind-feature! 'gerbil-smp #f 0 self))))
