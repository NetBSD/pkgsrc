$NetBSD: patch-src_third__party_s2_strings_split.h,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/strings/split.h.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/strings/split.h
@@ -41,7 +41,7 @@ using namespace std;
 void SplitStringAllowEmpty(const string& full, const char* delim,
                            vector<string>* res);
 void SplitStringToHashsetAllowEmpty(const string& full, const char* delim,
-                                    hash_set<string>* res);
+                                    s2_hash_set<string>* res);
 void SplitStringToSetAllowEmpty(const string& full, const char* delim,
                                 set<string>* res);
 // The even-positioned (0-based) components become the keys for the
@@ -50,7 +50,7 @@ void SplitStringToSetAllowEmpty(const st
 // if the key was already present in the hash table, or will be the
 // empty string if the key is a newly inserted key.
 void SplitStringToHashmapAllowEmpty(const string& full, const char* delim,
-                                    hash_map<string, string>* result);
+                                    s2_hash_map<string, string>* result);
 
 // ----------------------------------------------------------------------
 // SplitStringUsing()
@@ -66,7 +66,7 @@ void SplitStringToHashmapAllowEmpty(cons
 void SplitStringUsing(const string& full, const char* delim,
                       vector<string>* res);
 void SplitStringToHashsetUsing(const string& full, const char* delim,
-                               hash_set<string>* res);
+                               s2_hash_set<string>* res);
 void SplitStringToSetUsing(const string& full, const char* delim,
                            set<string>* res);
 // The even-positioned (0-based) components become the keys for the
@@ -75,7 +75,7 @@ void SplitStringToSetUsing(const string&
 // if the key was already present in the hash table, or will be the
 // empty string if the key is a newly inserted key.
 void SplitStringToHashmapUsing(const string& full, const char* delim,
-                               hash_map<string, string>* result);
+                               s2_hash_map<string, string>* result);
 
 // ----------------------------------------------------------------------
 // SplitOneIntToken()
