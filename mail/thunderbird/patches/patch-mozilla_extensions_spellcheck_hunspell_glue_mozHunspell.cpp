$NetBSD: patch-mozilla_extensions_spellcheck_hunspell_glue_mozHunspell.cpp,v 1.3 2018/03/29 10:19:31 wiz Exp $

--- mozilla/extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2017-04-14 04:53:08.000000000 +0000
+++ mozilla/extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -381,6 +381,14 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("@LOCALBASE@/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
