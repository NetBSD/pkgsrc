$NetBSD: patch-utils_Config.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- utils/Config.cpp.orig	2013-04-30 12:13:38.000000000 +0000
+++ utils/Config.cpp
@@ -42,7 +42,7 @@ Config::~Config()
 {
     XTRACE();
 
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_keyValueMap.begin(); ci!=_keyValueMap.end(); ci++)
     {
         delete ci->second;
@@ -58,7 +58,7 @@ Config::~Config()
 
 void Config::getConfigItemList( list<ConfigItem> &ciList)
 {
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_keyValueMap.begin(); ci!=_keyValueMap.end(); ci++)
     {
 	ConfigItem item;
@@ -275,9 +275,9 @@ void Config::removeTrans( const string &
 }
 
 void Config::removeImpl( const string &keyword,
-	hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap)
+	hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap)
 {
-    hash_map<string, Value*, hash<string> >::iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::iterator ci;
     ci = kvmap.find( keyword);
 
     if( ci!=kvmap.end())
@@ -316,7 +316,7 @@ void Config::saveToFile( bool truncate)
     outfile << "# This is a generated file. Edit carefully!" << endl;
     outfile << "# --- Variable section --- " << endl;
  
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     for( ci=_keyValueMap.begin(); ci!=_keyValueMap.end(); ci++)
     {
         Value *val = ci->second;
@@ -378,9 +378,9 @@ bool Config::getFloat( const string &key
 }
 
 bool Config::getStringImpl( const string &keyword, string &value, 
-	hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap)
+	hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap)
 {
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     ci = kvmap.find( keyword);
 
     if( ci!=kvmap.end())
@@ -393,9 +393,9 @@ bool Config::getStringImpl( const string
 }
 
 bool Config::getIntegerImpl( const string &keyword, int &value, 
-	hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap)
+	hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap)
 {
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     ci = kvmap.find( keyword);
 
     if( ci!=kvmap.end())
@@ -408,9 +408,9 @@ bool Config::getIntegerImpl( const strin
 }
 
 bool Config::getBooleanImpl( const string &keyword, bool &value,
-	hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap)
+	hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap)
 {
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     ci = kvmap.find( keyword);
 
     if( ci!=kvmap.end())
@@ -423,9 +423,9 @@ bool Config::getBooleanImpl( const strin
 }
 
 bool Config::getFloatImpl( const string &keyword, float &value,
-	hash_map< string, Value*, hash<string>, equal_to<string> > &kvmap)
+	hash_map< string, Value*, ::HASH_NAMESPACE::hash<string>, equal_to<string> > &kvmap)
 {
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
     ci = kvmap.find( keyword);
 
     if( ci!=kvmap.end())
@@ -440,7 +440,7 @@ bool Config::getFloatImpl( const string 
 void Config::dump( void)
 {
     XTRACE();
-    hash_map<string, Value*, hash<string> >::const_iterator ci;
+    hash_map<string, Value*, ::HASH_NAMESPACE::hash<string> >::const_iterator ci;
 
     for( ci=_keyValueMap.begin(); ci!=_keyValueMap.end(); ci++)
     {
