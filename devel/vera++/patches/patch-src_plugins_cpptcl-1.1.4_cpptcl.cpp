$NetBSD: patch-src_plugins_cpptcl-1.1.4_cpptcl.cpp,v 1.1 2013/05/11 21:31:21 joerg Exp $

--- src/plugins/cpptcl-1.1.4/cpptcl.cpp.orig	2013-05-10 14:40:07.000000000 +0000
+++ src/plugins/cpptcl-1.1.4/cpptcl.cpp
@@ -166,7 +166,7 @@ namespace // unnamed
 {
 
 // map of polymorphic callbacks
-typedef map<string, shared_ptr<callback_base> > callback_interp_map;
+typedef map<string, boost::shared_ptr<callback_base> > callback_interp_map;
 typedef map<Tcl_Interp *, callback_interp_map> callback_map;
 
 callback_map callbacks;
@@ -179,7 +179,7 @@ typedef map<Tcl_Interp *, policies_inter
 policies_map call_policies;
 
 // map of object handlers
-typedef map<string, shared_ptr<class_handler_base> > class_interp_map;
+typedef map<string, boost::shared_ptr<class_handler_base> > class_interp_map;
 typedef map<Tcl_Interp *, class_interp_map> class_handlers_map;
 
 class_handlers_map class_handlers;
@@ -500,7 +500,7 @@ class_handler_base::class_handler_base()
 }
 
 void class_handler_base::register_method(string const &name,
-     shared_ptr<object_cmd_base> ocb, policies const &p)
+     boost::shared_ptr<object_cmd_base> ocb, policies const &p)
 {
      methods_[name] = ocb;
      policies_[name] = p;
@@ -999,7 +999,7 @@ void interpreter::clear_definitions(Tcl_
 }
 
 void interpreter::add_function(string const &name,
-     shared_ptr<callback_base> cb, policies const &p)
+     boost::shared_ptr<callback_base> cb, policies const &p)
 {
      Tcl_CreateObjCommand(interp_, name.c_str(),
           callback_handler, 0, 0);
@@ -1009,13 +1009,13 @@ void interpreter::add_function(string co
 }
 
 void interpreter::add_class(string const &name,
-     shared_ptr<class_handler_base> chb)
+     boost::shared_ptr<class_handler_base> chb)
 {
      class_handlers[interp_][name] = chb;
 }
 
 void interpreter::add_constructor(string const &name,
-     shared_ptr<class_handler_base> chb, shared_ptr<callback_base> cb,
+     boost::shared_ptr<class_handler_base> chb, boost::shared_ptr<callback_base> cb,
      policies const &p)
 {
      Tcl_CreateObjCommand(interp_, name.c_str(),
