$NetBSD: patch-utils_Config.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- utils/Config.hpp.orig	2013-04-30 12:11:40.000000000 +0000
+++ utils/Config.hpp
@@ -91,23 +91,23 @@ private:
     Config &operator=(const Config&);
 
     void removeImpl( const string &keyword,
-	    hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap);
+	    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap);
 
     bool getStringImpl( const string &keyword, string &value, 
-	    hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap);
+	    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap);
     bool getIntegerImpl( const string &keyword, int &value, 
-	    hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap);
+	    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap);
     bool getBooleanImpl( const string &keyword, bool &value,
-	    hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap);
+	    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap);
     bool getFloatImpl( const string &keyword, float &value,
-	    hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap);
+	    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap);
 
     string _defaultConfigFileName;
     string _subdir;
     string _configDirectory;
     list<ConfigHandler*> _configHandlerList;
-    hash_map< string, Value*, hash<string>, equal_to<string> > _keyValueMap;
-    hash_map< string, Value*, hash<string>, equal_to<string> > _keyValueMapTrans;
+    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > _keyValueMap;
+    hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > _keyValueMapTrans;
 };
 
 typedef Singleton<Config> ConfigS;
