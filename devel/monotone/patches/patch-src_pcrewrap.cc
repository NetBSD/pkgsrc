$NetBSD: patch-src_pcrewrap.cc,v 1.1 2018/09/13 21:14:45 gavan Exp $

--- src/pcrewrap.cc.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/pcrewrap.cc
@@ -74,7 +74,7 @@ get_capturecount(void const * bd)
 namespace pcre
 {
   typedef map<char const *,
-              pair<struct real_pcre const *, struct pcre_extra const *> >
+              pair<struct real_pcre8_or_16 const *, struct pcre_extra const *> >
               regex_cache;
 
   class regex_cache_manager
@@ -86,7 +86,7 @@ public:
       }
 
     void store(char const * pattern,
-               pair<struct real_pcre const *, struct pcre_extra const *>
+               pair<struct real_pcre8_or_16 const *, struct pcre_extra const *>
                data)
       {
         cache[pattern] = data;
