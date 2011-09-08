$NetBSD: patch-agg24-include-agg_renderer_outline_aa.h,v 1.1 2011/09/08 00:13:31 joerg Exp $

Don't leak non-const reference to const private member.

--- agg24/include/agg_renderer_outline_aa.h.orig	2011-09-07 14:29:12.000000000 +0000
+++ agg24/include/agg_renderer_outline_aa.h
@@ -1365,7 +1365,6 @@ namespace agg
         //---------------------------------------------------------------------
         void profile(const line_profile_aa& prof) { m_profile = &prof; }
         const line_profile_aa& profile() const { return *m_profile; }
-        line_profile_aa& profile() { return *m_profile; }
 
         //---------------------------------------------------------------------
         int subpixel_width() const { return m_profile->subpixel_width(); }
