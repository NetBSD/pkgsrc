$NetBSD: patch-src_extension_internal_pdfinput_poppler-transition-api.h,v 1.1 2019/01/06 08:41:01 markd Exp $

support for poppler 0.72 from upstream by way of linuxfromscratch 

--- /dev/null	2018-11-05 02:51:29.413333349 +0000
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -0,0 +1,43 @@
+#ifndef SEEN_POPPLER_TRANSITION_API_H
+#define SEEN_POPPLER_TRANSITION_API_H
+
+#include <glib/poppler-features.h>
+
+#if POPPLER_CHECK_VERSION(0,72,0)
+#define getCString c_str
+#endif
+
+#if POPPLER_CHECK_VERSION(0,70,0)
+#define _POPPLER_CONST const
+#else
+#define _POPPLER_CONST
+#endif
+
+#if POPPLER_CHECK_VERSION(0,69,0)
+#define _POPPLER_DICTADD(dict, key, obj) (dict).dictAdd(key, std::move(obj))
+#elif POPPLER_CHECK_VERSION(0,58,0)
+#define _POPPLER_DICTADD(dict, key, obj) (dict).dictAdd(copyString(key), std::move(obj))
+#else
+#define _POPPLER_DICTADD(dict, key, obj) (dict).dictAdd(copyString(key), &obj)
+#endif
+
+#if POPPLER_CHECK_VERSION(0,58,0)
+#define POPPLER_NEW_OBJECT_API
+#define _POPPLER_FREE(obj)
+#define _POPPLER_CALL(ret, func) (ret = func())
+#define _POPPLER_CALL_ARGS(ret, func, ...) (ret = func(__VA_ARGS__))
+#else
+#define _POPPLER_FREE(obj) (obj).free()
+#define _POPPLER_CALL(ret, func) (*func(&ret))
+#define _POPPLER_CALL_ARGS(ret, func, ...) (*func(__VA_ARGS__, &ret))
+#endif
+
+#if POPPLER_CHECK_VERSION(0, 29, 0)
+#define POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API
+#endif
+
+#if POPPLER_CHECK_VERSION(0, 25, 0)
+#define POPPLER_EVEN_NEWER_COLOR_SPACE_API
+#endif
+
+#endif
