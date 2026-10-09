$NetBSD: patch-src_bootstrap_gerbil_expander_root~0.scm,v 1.1 2026/10/09 14:31:31 ktnb Exp $

Don't failed due to an unsupported sys-type

--- src/bootstrap/gerbil/expander/root~0.scm.orig	2026-10-06 16:03:12.063681225 +0000
+++ src/bootstrap/gerbil/expander/root~0.scm
@@ -819,11 +819,14 @@
                                     '#f
                                     '0
                                     _%self139019%_)
-                                   (gx#core-bind-feature!__%
-                                    (string->symbol _%sys-prefix139063%_)
-                                    '#f
-                                    '0
-                                    _%self139019%_))
+                                   (if (eq? (string->symbol _%sys-prefix139063%_)
+                                             _%sys-type139055%_)
+                                     '#!void
+                                     (gx#core-bind-feature!__%
+                                      (string->symbol _%sys-prefix139063%_)
+                                      '#f
+                                      '0
+                                      _%self139019%_)))
                                  _%$e139060%_)
                                 '#!void))))))
               (if (pair? _%g139032139044%_)
