$NetBSD: patch-ext_gobject-introspection_rb-gi-function-info.c,v 1.1 2017/07/25 13:38:34 taca Exp $

* Avoid typedef RBGICallback again on compilers prior to c11, such as
  gcc 4.8.5 on NetBSD 6.1_STABLE.  They treat it redefinition of
  RBGICallback.

--- ext/gobject-introspection/rb-gi-function-info.c.orig	2017-07-25 08:10:51.000000000 +0000
+++ ext/gobject-introspection/rb-gi-function-info.c
@@ -34,13 +34,13 @@
 #define RG_TARGET_NAMESPACE rb_cGIFunctionInfo
 #define SELF(self) RVAL2GI_FUNCTION_INFO(self)
 
-typedef struct _RBGICallback {
+struct _RBGICallback {
     GIArgInfo *arg_info;
     GITypeInfo *type_info;
     GICallbackInfo *callback_info;
     ffi_cif cif;
     ffi_closure *closure;
-} RBGICallback;
+};
 
 static VALUE RG_TARGET_NAMESPACE;
 static VALUE rb_cGLibError;
