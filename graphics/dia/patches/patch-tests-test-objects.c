$NetBSD: patch-tests-test-objects.c,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/9c481f649414190bf8d6741cbca1777e9766756b
via Fedora

--- tests/test-objects.c				2014-08-24 17:46:02.000000000 +0200
+++ tests/test-objects.c.g_test_add_data_func_2	2024-03-03 01:01:53.832977690 +0100
@@ -39,8 +39,9 @@
 int num_objects = 0;
 
 static void
-_test_creation (const DiaObjectType *type)
+_test_creation (gconstpointer user_data)
 {
+  const DiaObjectType *type = (const DiaObjectType *)user_data;
   int i;
   Handle *h1 = NULL, *h2 = NULL;
   Point point = {0, 0};
@@ -112,8 +113,9 @@
 }
 
 static void
-_test_copy (const DiaObjectType *type)
+_test_copy (gconstpointer user_data)
 {
+  const DiaObjectType *type = (const DiaObjectType *)user_data;
   Handle *h1 = NULL, *h2 = NULL;
   Point from = {0, 0};
   DiaObject *oc, *o = type->ops->create (&from, type->default_user_data, &h1, &h2);
@@ -172,8 +174,9 @@
 }
 
 static void
-_test_movement (const DiaObjectType *type)
+_test_movement (gconstpointer user_data)
 {
+  const DiaObjectType *type = (const DiaObjectType *)user_data;
   Handle *h1 = NULL, *h2 = NULL;
   Point from = {0, 0};
   DiaObject *o = type->ops->create (&from, type->default_user_data, &h1, &h2);
@@ -215,8 +218,9 @@
 }
 
 static void
-_test_change (const DiaObjectType *type)
+_test_change (gconstpointer user_data)
 {
+  const DiaObjectType *type = (const DiaObjectType *)user_data;
   Handle *h1 = NULL, *h2 = NULL;
   Point from = {0, 0};
   DiaObject *o = type->ops->create (&from, type->default_user_data, &h1, &h2);
