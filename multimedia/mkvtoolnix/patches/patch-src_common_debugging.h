$NetBSD: patch-src_common_debugging.h,v 1.1 2018/12/13 19:52:14 adam Exp $

Fix for boost-1.69.0.

--- src/common/debugging.h.orig	2018-12-13 11:59:23.000000000 +0000
+++ src/common/debugging.h
@@ -57,7 +57,7 @@ class debugging_option_c {
       if (boost::logic::indeterminate(m_requested))
         m_requested = debugging_c::requested(m_option);
 
-      return m_requested;
+      return m_requested ? true : false;
     }
   };
 
