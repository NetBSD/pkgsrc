$NetBSD: patch-gi_pygi-cache.h,v 1.1 2014/11/01 11:25:41 obache Exp $

* Remove redefinitions of function and vfunc cache typedefs
  https://bugzilla.gnome.org/show_bug.cgi?id=737874

--- gi/pygi-cache.h.orig	2014-09-10 22:10:32.000000000 +0000
+++ gi/pygi-cache.h
@@ -197,7 +197,7 @@ struct _PyGICallableCache
                                      GICallableInfo *callable_info);
 };
 
-typedef struct _PyGIFunctionCache {
+struct _PyGIFunctionCache {
     PyGICallableCache callable_cache;
 
     /* An invoker with ffi_cif already setup */
@@ -207,13 +207,13 @@ typedef struct _PyGIFunctionCache {
                          PyGIInvokeState *state,
                          PyObject *py_args,
                          PyObject *py_kwargs);
-} PyGIFunctionCache;
+} ;
 
-typedef struct _PyGIVFuncCache {
+struct _PyGIVFuncCache {
     PyGIFunctionWithInstanceCache fwi_cache;
 
     GIBaseInfo *info;
-} PyGIVFuncCache;
+};
 
 
 gboolean
