$NetBSD: patch-external_imgui_imgui__impl__opengl3__loader.h,v 1.1 2024/08/10 12:04:36 nia Exp $

NetBSD and OpenBSD do not necessarily have a .so.1 for libGL.

--- external/imgui/imgui_impl_opengl3_loader.h.orig	2024-08-10 11:58:13.574917029 +0000
+++ external/imgui/imgui_impl_opengl3_loader.h
@@ -662,7 +662,11 @@ static GL3WglProc (*glx_get_proc_address
 
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
