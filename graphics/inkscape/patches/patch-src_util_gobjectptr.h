$NetBSD: patch-src_util_gobjectptr.h,v 1.1 2025/04/30 19:45:31 tnn Exp $

Compile fix: https://gitlab.com/inkscape/inkscape/-/commit/eb6dadcf1a5c660167ba43f3606c8e7cc6529787.patch

--- src/util/gobjectptr.h.orig	2024-04-22 21:00:30.000000000 +0000
+++ src/util/gobjectptr.h
@@ -20,7 +20,7 @@ public:
     GObjectPtr() = default;
     explicit GObjectPtr(T *p, bool add_ref = false) : _p(p) { if (add_ref) _ref(); }
     GObjectPtr(GObjectPtr const &other) : _p(other._p) { _ref(); }
-    GObjectPtr &operator=(GObjectPtr const &other) { if (&other != this) { _unref(); _p = other.p; _ref(); } return *this; }
+    GObjectPtr &operator=(GObjectPtr const &other) { if (&other != this) { _unref(); _p = other._p; _ref(); } return *this; }
     GObjectPtr(GObjectPtr &&other) noexcept : _p(other._p) { other._p = nullptr; }
     GObjectPtr &operator=(GObjectPtr &&other) { if (&other != this) { _unref(); _p = other._p; other._p = nullptr; } return *this; }
     ~GObjectPtr() { _unref(); }
