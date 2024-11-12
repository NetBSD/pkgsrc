$NetBSD: patch-extern_imgui__patched_backends_imgui__impl__opengl3__loader.h,v 1.1 2024/11/12 21:27:33 nia Exp $

NetBSD does not have libGL.so.1 when using xsrc.

--- extern/imgui_patched/backends/imgui_impl_opengl3_loader.h.orig	2024-11-12 21:21:17.283414043 +0000
+++ extern/imgui_patched/backends/imgui_impl_opengl3_loader.h
@@ -666,7 +666,11 @@ static GL3WglProc (*glx_get_proc_address
 
 static int open_libgl(void)
 {
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+    libgl = dlopen("libGL.so", RTLD_LAZY | RTLD_LOCAL);
+#else
     libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_LOCAL);
+#endif
     if (!libgl)
         return GL3W_ERROR_LIBRARY_OPEN;
     *(void **)(&glx_get_proc_address) = dlsym(libgl, "glXGetProcAddressARB");
