$NetBSD: patch-include_configcontainer.h,v 1.1 2016/12/16 00:00:25 joerg Exp $

Avoid unnecessary string copies.

Passing non-POD types to variadic functions is UB, so use C++11 rvalues
and proper typing.

--- include/configcontainer.h.orig	2016-12-15 14:37:54.279263729 +0000
+++ include/configcontainer.h
@@ -8,8 +8,8 @@ namespace newsbeuter {
 
 struct configdata {
 	enum configdata_type { INVALID, BOOL, INT, STR, PATH, ALIAS, ENUM };
-	configdata(std::string v = "", configdata_type t = INVALID, bool m = false) : value(v), default_value(v), type(t), multi_option(m) { }
-	configdata(std::string v, ...);
+	configdata(const std::string &v = "", configdata_type t = INVALID, bool m = false) : value(v), default_value(v), type(t), multi_option(m) { }
+	configdata(const std::string &v, std::set<std::string> &&);
 	std::string value;
 	std::string default_value;
 	configdata_type type;
