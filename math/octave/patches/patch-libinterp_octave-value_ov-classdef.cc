$NetBSD: patch-libinterp_octave-value_ov-classdef.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- libinterp/octave-value/ov-classdef.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libinterp/octave-value/ov-classdef.cc
@@ -1937,6 +1937,11 @@ cdef_object_scalar::is_partially_constru
   return true;
 }
 
+void cdef_object_scalar::mark_as_constructed (const cdef_class& cls)
+{
+  ctor_list.erase (cls);
+}
+
 handle_cdef_object::~handle_cdef_object (void)
 {
 #if DEBUG_TRACE
