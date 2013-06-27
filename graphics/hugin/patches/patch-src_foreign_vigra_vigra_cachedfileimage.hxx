$NetBSD: patch-src_foreign_vigra_vigra_cachedfileimage.hxx,v 1.1 2013/06/27 15:51:49 joerg Exp $

--- src/foreign/vigra/vigra/cachedfileimage.hxx.orig	2013-06-25 21:58:48.000000000 +0000
+++ src/foreign/vigra/vigra/cachedfileimage.hxx
@@ -554,11 +554,7 @@ class NotifyingDirectionSelector;
 template <class T, class Notify>
 class NotifyingDirectionSelector<UnstridedArrayTag, T, Notify>
 {
-#ifdef __GNUC__
-friend class Notify::self_type;
-#else
 friend typename Notify::self_type;
-#endif
 protected:
     NotifyingDirectionSelector(T base = 0) : current_(base), notify_(NULL) {}
     NotifyingDirectionSelector(NotifyingDirectionSelector const & rhs) : current_(rhs.current_), notify_(NULL) {}
