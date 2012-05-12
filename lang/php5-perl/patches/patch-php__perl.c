$NetBSD: patch-php__perl.c,v 1.1 2012/05/12 11:40:06 obache Exp $

* fixes build with PHP>=5.3

--- php_perl.c.orig	2004-12-17 10:49:46.000000000 +0000
+++ php_perl.c
@@ -55,6 +55,19 @@
 #include "SAPI.h"
 #include "php_perl.h"
 
+#ifndef Z_ISREF_P
+#define Z_ISREF_P(z)		(z)->is_ref
+#endif
+#ifndef Z_SET_ISREF_P
+#define Z_SET_ISREF_P(z)	(z)->is_ref = 1
+#endif
+#ifndef Z_ADDREF_P
+#define Z_ADDREF_P(z)		(z)->refcount++
+#endif
+#ifndef Z_SET_REFCOUNT_P
+#define Z_SET_REFCOUNT_P(pz,rc)	(pz)->refcount = (rc)
+#endif
+
 ZEND_BEGIN_MODULE_GLOBALS(perl)
   PerlInterpreter *perl;
   HashTable       perl_objects; /* this hash is used to make one to one
@@ -340,14 +353,14 @@ static SV* php_perl_zval_to_sv_ref(PerlI
 {
   SV* sv;
 
-  if ((zv->is_ref || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) &&
+  if ((Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) &&
       zend_hash_find(var_hash, (char*)zv, sizeof(zv), (void**)&sv) == SUCCESS) {
     sv = *(SV**)sv;
     SvREFCNT_inc(sv);
     return sv;
   }
   sv = php_perl_zval_to_sv_noref(my_perl, zv, var_hash TSRMLS_CC);
-  if (zv->is_ref || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) {
+  if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) {
     zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
   }
   return sv;
@@ -390,7 +403,7 @@ static SV* php_perl_zval_to_sv_noref(Per
         SV* sv = (SV*)newRV((SV*)hv);
         zval** zv_ptr;
 
-        if (zv->is_ref || Z_TYPE_P(zv) == IS_ARRAY) {
+        if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_ARRAY) {
           zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
         }
 
@@ -420,7 +433,7 @@ static SV* php_perl_zval_to_sv_noref(Per
         SV* sv = (SV*)newRV((SV*)av);
         zval** zv_ptr;
 
-        if (zv->is_ref || Z_TYPE_P(zv) == IS_ARRAY) {
+        if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_ARRAY) {
           zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
         }
 
@@ -480,9 +493,9 @@ static zval* php_perl_sv_to_zval_ref(Per
       FREE_ZVAL(zv);
     }
     if (Z_TYPE_PP(z) != IS_OBJECT) {
-      (*z)->is_ref = 1;
+      Z_SET_ISREF_P(*z);
     }
-    (*z)->refcount++;
+    Z_ADDREF_P(*z);
     return *z;
   }
 
@@ -750,7 +763,7 @@ static zval* php_perl_get(zval *object T
   }
   retval = php_perl_sv_to_zval(my_perl, obj->sv, NULL TSRMLS_CC);
   /* ensure we're creating a temporary variable */
-  if (retval) {retval->refcount = 0;}
+  if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
   return retval;
 }
 
@@ -824,8 +837,8 @@ static zval* php_perl_read_dimension(zva
         obj->context = PERL_SCALAR;
 
         ALLOC_INIT_ZVAL(retval);
-        retval->refcount = 0;
-        retval->is_ref = 1;
+        Z_SET_REFCOUNT_P(retval, 0);
+        Z_SET_ISREF_P(retval);
         retval->type = IS_OBJECT;
         Z_OBJ_HT_P(retval) = &php_perl_proxy_handlers;
         Z_OBJ_HANDLE_P(retval) = zend_objects_store_put(obj, php_perl_destructor, NULL, NULL TSRMLS_CC);        
@@ -833,7 +846,7 @@ static zval* php_perl_read_dimension(zva
         ALLOC_INIT_ZVAL(retval);
         retval = php_perl_sv_to_zval(my_perl, *prop_val, retval TSRMLS_CC);
         /* ensure we're creating a temporary variable */
-        if (retval) {retval->refcount = 0;}
+        if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
       }
     }
   } else if (SvTYPE(sv) == SVt_PVHV) {
@@ -973,7 +986,7 @@ static zval* php_perl_read_property(zval
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -990,7 +1003,7 @@ static zval* php_perl_read_property(zval
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -1007,7 +1020,7 @@ static zval* php_perl_read_property(zval
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -1085,15 +1098,15 @@ static zval* php_perl_read_property(zval
       obj->context = PERL_SCALAR;
 
       ALLOC_INIT_ZVAL(retval);
-      retval->refcount = 0;
-      retval->is_ref = 1;
+      Z_SET_REFCOUNT_P(retval, 0);
+      Z_SET_ISREF_P(retval);
       retval->type = IS_OBJECT;
       Z_OBJ_HT_P(retval) = &php_perl_proxy_handlers;
       Z_OBJ_HANDLE_P(retval) = zend_objects_store_put(obj, php_perl_destructor, NULL, NULL TSRMLS_CC);        
     } else {
       retval = php_perl_sv_to_zval(my_perl, sv, retval TSRMLS_CC);
       /* ensure we're creating a temporary variable */
-      if (retval) {retval->refcount = 0;}
+      if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
     }
   }
 
@@ -1755,7 +1768,7 @@ static void php_perl_iterator_rewind(zen
 zend_object_iterator *php_perl_get_iterator(zend_class_entry *ce, zval *object TSRMLS_DC)
 {
   zend_object_iterator *iterator = emalloc(sizeof(zend_object_iterator));
-  object->refcount++;
+  Z_ADDREF_P(object);
   iterator->data = (void*)object;
   iterator->funcs = &php_perl_iterator_funcs;
 
