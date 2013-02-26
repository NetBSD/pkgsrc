$NetBSD: patch-inc_config.hpp,v 1.1 2013/02/26 10:26:27 joerg Exp $

--- inc/config.hpp.orig	2013-02-25 19:32:06.000000000 +0000
+++ inc/config.hpp
@@ -31,6 +31,19 @@
 #include <libxml++/nodes/element.h>
 #include <libxml++/nodes/textnode.h>
 
+
+namespace serialise
+{
+template<>
+class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
+{
+public:
+	typedef Glib::ustring data_type;
+
+	virtual std::string to_string(const data_type& from) const;
+};
+}
+
 namespace Gobby
 {
 
@@ -460,15 +473,6 @@ public:
 };
 
 template<>
-class default_context_to<Glib::ustring>: public context_base_to<Glib::ustring>
-{
-public:
-	typedef Glib::ustring data_type;
-
-	virtual std::string to_string(const data_type& from) const;
-};
-
-template<>
 class default_context_from<Glib::ustring>:
 	public context_base_from<Glib::ustring>
 {
