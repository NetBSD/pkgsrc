$NetBSD: patch-src_class.h,v 1.1 2012/03/29 11:40:19 wiz Exp $

Fix build with clang-3.1.

--- src/class.h.orig	2007-11-15 05:34:32.000000000 +0000
+++ src/class.h
@@ -171,7 +171,7 @@ super.add as well.
 
 #define CLASS(class,super_class)			\
   typedef struct class *class;				\
-  inline void class ## _init(void);			\
+  void class ## _init(void);			\
   void class ## _Alloc(class this);			\
   extern int __ ## class ## _initialised;		\
   extern struct class __ ## class;			\
@@ -209,7 +209,7 @@ super.add as well.
 
 #define VIRTUAL(class,superclass)				\
   struct class __ ## class;					\
-  inline void class ## _init(void) {					\
+  void class ## _init(void) {					\
     if(!__ ## class ## _initialised) {					\
       class ## _Alloc(&__ ## class);					\
       __ ## class ## _initialised = 1;					\
@@ -233,7 +233,7 @@ super.add as well.
 
 #define VIRTUAL(class,superclass)				\
   struct class __ ## class;					\
-  inline void class ## _init(void) {					\
+  void class ## _init(void) {					\
     if(!__ ## class ## _initialised) {					\
       class ## _Alloc(&__ ## class);					\
       __ ## class ## _initialised = 1;					\
@@ -348,8 +348,8 @@ struct Object {
 #define GET_CLASS(name)				\
   &__ ## name
 
-inline void Object_init(void);
-inline void Object_Alloc(Object this);
+void Object_init(void);
+void Object_Alloc(Object this);
 
 extern struct Object __Object;
 
