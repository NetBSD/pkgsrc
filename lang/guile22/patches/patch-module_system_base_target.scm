$NetBSD: patch-module_system_base_target.scm,v 1.1 2022/03/07 23:03:14 wiz Exp $

Crude patch to make target.scm conform to vendor field of gnu-tripplet
being optional.

Tested with GnuTLS Guile bindings, where the current implementation
prevents building on any platform which isn't conforming to having a
vendor part.

Full explanation: https://gitlab.com/gnutls/gnutls/-/issues/996

--- module/system/base/target.scm.orig  2018-06-18 14:14:47.000000000 +0200
+++ module/system/base/target.scm       2020-05-14 15:51:14.664581289 +0200
@@ -46,7 +46,7 @@
           (let ((parts (string-split target #\-)))
             (or (< (length parts) 3)
                 (or-map string-null? parts))))
-      (error "invalid target" target)))
+      (string-append "invalid target" target)))
 
 (define (with-target target thunk)
   (validate-target target)
