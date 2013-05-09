$NetBSD: patch-src_rpc_command.h,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/rpc/command.h.orig	2013-05-03 22:40:32.000000000 +0000
+++ src/rpc/command.h
@@ -41,13 +41,17 @@
 #include <limits>
 #include <inttypes.h>
 #include <torrent/object.h>
-#include <tr1/functional>
 
 #include <torrent/object.h>
 #include <torrent/data/file_list_iterator.h>
 
 // Move into config.h or something.
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+using std::function;
+#else
+#include <tr1/functional>
+using std::tr1::function;
+#endif
 
 namespace core {
   class Download;
@@ -111,7 +115,7 @@ typedef rt_triple<int, void*, void*> tar
 class command_base;
 
 typedef const torrent::Object (*command_base_call_type)(command_base*, target_type, const torrent::Object&);
-typedef tr1::function<torrent::Object (target_type, const torrent::Object&)> base_function;
+typedef function<torrent::Object (target_type, const torrent::Object&)> base_function;
 
 template <typename tmpl> struct command_base_is_valid {};
 template <command_base_call_type tmpl_func> struct command_base_is_type {};
@@ -250,7 +254,7 @@ command_base::_call(command_base* cmd, t
 }
 
 #define COMMAND_BASE_TEMPLATE_TYPE(func_type, func_parm)                \
-  template <typename T, int proper = target_type_id<T>::proper_type> struct func_type { typedef tr1::function<func_parm> type; }; \
+  template <typename T, int proper = target_type_id<T>::proper_type> struct func_type { typedef function<func_parm> type; }; \
                                                                         \
   template <> struct command_base_is_valid<func_type<target_type>::type>                { static const int value = 1; }; \
   template <> struct command_base_is_valid<func_type<core::Download*>::type>            { static const int value = 1; }; \
