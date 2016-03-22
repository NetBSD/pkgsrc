$NetBSD: patch-py_obj.h,v 1.1 2016/03/22 19:01:17 joerg Exp $

Avoid Undefined Behavior.

--- py/obj.h.orig	2016-03-02 16:07:50.524241926 +0000
+++ py/obj.h
@@ -81,7 +81,7 @@ typedef struct _mp_obj_base_t mp_obj_bas
 static inline bool MP_OBJ_IS_SMALL_INT(mp_const_obj_t o)
     { return ((((mp_int_t)(o)) & 1) != 0); }
 #define MP_OBJ_SMALL_INT_VALUE(o) (((mp_int_t)(o)) >> 1)
-#define MP_OBJ_NEW_SMALL_INT(small_int) ((mp_obj_t)((((mp_int_t)(small_int)) << 1) | 1))
+#define MP_OBJ_NEW_SMALL_INT(small_int) ((mp_obj_t)((((mp_int_t)(small_int)) * 2) | 1))
 
 static inline bool MP_OBJ_IS_QSTR(mp_const_obj_t o)
     { return ((((mp_int_t)(o)) & 3) == 2); }
