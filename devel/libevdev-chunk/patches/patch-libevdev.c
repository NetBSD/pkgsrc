$NetBSD: patch-libevdev.c,v 1.1 2026/04/13 15:36:31 kikadf Exp $

* Add missing functions

--- libevdev.c.orig	2023-11-11 14:32:38.000000000 +0000
+++ libevdev.c
@@ -140,3 +140,31 @@ libevdev_event_code_from_name(unsigned i
 
 	return entry ? (int)entry->value : -1;
 }
+
+int
+libevdev_event_type_from_name(const char *name)
+{
+	struct name_lookup lookup;
+	const struct name_entry *entry;
+
+	lookup.name = name;
+	lookup.len = strlen(name);
+
+	entry = lookup_name(ev_names, ARRAY_LENGTH(ev_names), &lookup);
+
+	return entry ? (int)entry->value : -1;
+}
+
+int
+libevdev_property_from_name(const char *name)
+{
+	struct name_lookup lookup;
+	const struct name_entry *entry;
+
+	lookup.name = name;
+	lookup.len = strlen(name);
+
+	entry = lookup_name(prop_names, ARRAY_LENGTH(prop_names), &lookup);
+
+	return entry ? (int)entry->value : -1;
+}
