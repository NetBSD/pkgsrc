$NetBSD: patch-libinterp_octave-value_ov-classdef.h,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- libinterp/octave-value/ov-classdef.h.orig	2015-05-23 14:21:53.000000000 +0000
+++ libinterp/octave-value/ov-classdef.h
@@ -438,7 +438,7 @@ public:
 
   void mark_as_constructed (void) { ctor_list.clear (); }
 
-  void mark_as_constructed (const cdef_class& cls) { ctor_list.erase (cls); }
+  void mark_as_constructed (const cdef_class& cls);
 
   bool is_constructed (void) const { return ctor_list.empty (); }
 
