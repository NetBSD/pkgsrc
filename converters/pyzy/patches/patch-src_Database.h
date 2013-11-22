$NetBSD: patch-src_Database.h,v 1.1 2013/11/22 15:43:05 dholland Exp $

Work around C++ build error with gcc 4.5.

--- src/Database.h.orig	2012-07-13 02:46:33.000000000 +0000
+++ src/Database.h
@@ -79,7 +79,7 @@ public:
     static void finalize (void);
     static Database & instance (void)
     {
-        if (m_instance == NULL) {
+        if (!m_instance) {
             g_error ("Error: Please call InputContext::init () !");
         }
         return *m_instance;
