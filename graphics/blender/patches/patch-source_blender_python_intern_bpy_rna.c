$NetBSD: patch-source_blender_python_intern_bpy_rna.c,v 1.1 2019/03/27 11:05:57 markd Exp $

From 1db47a2ccd1e68994bf8140eba6cc2a26a2bc91f Mon Sep 17 00:00:00 2001
From: Campbell Barton <ideasman42@gmail.com>
Date: Thu, 12 Jul 2018 08:28:06 +0200
Subject: [PATCH] Fix PyRNA class registration w/ Python 3.7

In Python3.7 this now raises an error.

--- source/blender/python/intern/bpy_rna.c.orig	2018-03-23 15:22:25.000000000 +0000
+++ source/blender/python/intern/bpy_rna.c
@@ -7385,10 +7385,12 @@ static int bpy_class_validate_recursive(
 		if (!(flag & PROP_REGISTER))
 			continue;
 
+		/* TODO(campbell): Use Python3.7x _PyObject_LookupAttr(), also in the macro below. */
 		identifier = RNA_property_identifier(prop);
 		item = PyObject_GetAttrString(py_class, identifier);
 
 		if (item == NULL) {
+			PyErr_Clear();
 			/* Sneaky workaround to use the class name as the bl_idname */
 
 #define     BPY_REPLACEMENT_STRING(rna_attr, py_attr)                         \
@@ -7404,6 +7406,9 @@ static int bpy_class_validate_recursive(
 					}                                                         \
 					Py_DECREF(item);                                          \
 				}                                                             \
+				else {                                                        \
+					PyErr_Clear();                                        \
+				}                                                             \
 			}  /* intentionally allow else here */
 
 			if (false) {}  /* needed for macro */
