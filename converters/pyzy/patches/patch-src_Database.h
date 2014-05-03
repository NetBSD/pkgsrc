$NetBSD: patch-src_Database.h,v 1.2 2014/05/03 07:14:45 obache Exp $

* resolve ambiguous operator, changed to same way used in other place.
  http://code.google.com/p/pyzy/issues/detail?id=3

--- src/Database.h.orig	2012-07-13 02:46:33.000000000 +0000
+++ src/Database.h
@@ -79,7 +79,7 @@ public:
     static void finalize (void);
     static Database & instance (void)
     {
-        if (m_instance == NULL) {
+        if (m_instance.get () == NULL) {
             g_error ("Error: Please call InputContext::init () !");
         }
         return *m_instance;
