$NetBSD: patch-xen_include_xen_compat.h,v 1.1 2014/05/14 20:21:19 bouyer Exp $

--- xen/include/xen/compat.h.orig	2008-04-25 15:03:12.000000000 +0200
+++ xen/include/xen/compat.h	2014-05-14 16:24:55.000000000 +0200
@@ -126,12 +126,8 @@
 })
 
 
-#define CHECK_TYPE(name) \
-    typedef int __checkT ## name[1 - ((xen_ ## name ## _t *)0 != \
-                                   (compat_ ## name ## _t *)0) * 2]
-#define CHECK_TYPE_(k, n) \
-    typedef int __checkT ## k ## _ ## n[1 - ((k xen_ ## n *)0 != \
-                                          (k compat_ ## n *)0) * 2]
+#define CHECK_TYPE(name) /**/
+#define CHECK_TYPE_(k, n) /**/
 
 #define CHECK_SIZE(name) \
     typedef int __checkS ## name[1 - (sizeof(xen_ ## name ## _t) != \
@@ -140,30 +136,13 @@
     typedef int __checkS ## k ## _ ## n[1 - (sizeof(k xen_ ## n) != \
                                           sizeof(k compat_ ## n)) * 2]
 
-#define CHECK_FIELD(t, f) \
-    typedef int __checkF ## t ## __ ## f[1 - (&((xen_ ## t ## _t *)0)->f != \
-                                           &((compat_ ## t ## _t *)0)->f) * 2]
-#define CHECK_FIELD_(k, n, f) \
-    typedef int __checkF ## k ## _ ## n ## __ ## f[1 - (&((k xen_ ## n *)0)->f != \
-                                                     &((k compat_ ## n *)0)->f) * 2]
-
-#define CHECK_SUBFIELD_1(t, f1, f2) \
-    typedef int __checkF1 ## t ## __ ## f1 ## __ ## f2 \
-                [1 - (&((xen_ ## t ## _t *)0)->f1.f2 != \
-                   &((compat_ ## t ## _t *)0)->f1.f2) * 2]
-#define CHECK_SUBFIELD_1_(k, n, f1, f2) \
-    typedef int __checkF1 ## k ## _ ## n ## __ ## f1 ## __ ## f2 \
-                [1 - (&((k xen_ ## n *)0)->f1.f2 != \
-                   &((k compat_ ## n *)0)->f1.f2) * 2]
-
-#define CHECK_SUBFIELD_2(t, f1, f2, f3) \
-    typedef int __checkF2 ## t ## __ ## f1 ## __ ## f2 ## __ ## f3 \
-                [1 - (&((xen_ ## t ## _t *)0)->f1.f2.f3 != \
-                   &((compat_ ## t ## _t *)0)->f1.f2.f3) * 2]
-#define CHECK_SUBFIELD_2_(k, n, f1, f2, f3) \
-    typedef int __checkF2 ## k ## _ ## n ## __ ## f1 ## __ ## f2 ## __ ## f3 \
-                [1 - (&((k xen_ ## n *)0)->f1.f2.f3 != \
-                   &((k compat_ ## n *)0)->f1.f2.f3) * 2]
+#define CHECK_FIELD(t, f) /**/
+#define CHECK_FIELD_(k, n, f) /**/
+#define CHECK_SUBFIELD_1(t, f1, f2) /**/
+#define CHECK_SUBFIELD_1_(k, n, f1, f2) /**/
+
+#define CHECK_SUBFIELD_2(t, f1, f2, f3) /**/
+#define CHECK_SUBFIELD_2_(k, n, f1, f2, f3) /**/
 
 int hypercall_xlat_continuation(unsigned int *id, unsigned int mask, ...);
 
