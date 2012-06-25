$NetBSD: patch-c_doxymacs__parser.c,v 1.1 2012/06/25 11:18:39 joerg Exp $

--- c/doxymacs_parser.c.orig	2012-06-18 16:32:20.000000000 +0000
+++ c/doxymacs_parser.c
@@ -70,7 +70,7 @@ typedef struct _hash_entry
 
 hash_entry *symbol_hash[HASH_SIZE];
 
-inline unsigned int hash(const char *s)
+static inline unsigned int hash(const char *s)
 {
     unsigned int h = 0;
 
@@ -82,7 +82,7 @@ inline unsigned int hash(const char *s)
     return abs(h % HASH_SIZE);
 }
 
-inline void AddToHash(completion_list *cl)
+static inline void AddToHash(completion_list *cl)
 {
     unsigned int h = hash(cl->symbol);
     hash_entry **cur = &symbol_hash[h];
@@ -96,7 +96,7 @@ inline void AddToHash(completion_list *c
 }
 
 /* mmmmm... free hash */
-inline void FreeHash(void)
+static inline void FreeHash(void)
 {
     unsigned int i;
     for (i = 0; i < HASH_SIZE; i++)
@@ -117,7 +117,7 @@ inline void FreeHash(void)
 
 /* XML Helper Functions */
 
-inline char *XMLTagChild(xmlNodePtr node, const char *name)
+static inline char *XMLTagChild(xmlNodePtr node, const char *name)
 {
     xmlNodePtr cur = node->xmlChildrenNode;
 
@@ -141,7 +141,7 @@ inline char *XMLTagChild(xmlNodePtr node
     return NULL;
 }
 
-inline char *XMLTagAttr(xmlNodePtr node, const char *attr)
+static inline char *XMLTagAttr(xmlNodePtr node, const char *attr)
 {
     xmlAttrPtr props = node->properties;
 
@@ -167,7 +167,7 @@ inline char *XMLTagAttr(xmlNodePtr node,
 
 /* Look up functions for symbols and descriptions */
 
-inline completion_list *LookUpSymbol(const char *symbol)
+static inline completion_list *LookUpSymbol(const char *symbol)
 {
     unsigned int h = hash(symbol);
     hash_entry *cur = symbol_hash[h];
@@ -187,7 +187,7 @@ inline completion_list *LookUpSymbol(con
     return NULL;
 }
 
-inline desc_url_list *LookUpDesc(completion_list *entry, const char *desc)
+static inline desc_url_list *LookUpDesc(completion_list *entry, const char *desc)
 {
     desc_url_list *cur = entry->descs;
 
@@ -206,7 +206,7 @@ inline desc_url_list *LookUpDesc(complet
 
 /* Add the given name, description and url to our completion list */
 
-inline int AddToCompletionList(const char *name,
+static inline int AddToCompletionList(const char *name,
                                const char *desc, const char *url)
 {
     completion_list *check;
@@ -274,7 +274,7 @@ inline int AddToCompletionList(const cha
 }
 
 /* Encode the given string so that {X}Emacs will understand it */
-inline char *Encode(const char *s)
+static inline char *Encode(const char *s)
 {
     unsigned int extra_len = 0;
     char *c = (char *)s;
@@ -341,7 +341,7 @@ inline char *Encode(const char *s)
 
 /* Output the completion list in a way {X}Emacs can easily read in */
 
-inline int OutputCompletionList(void)
+static inline int OutputCompletionList(void)
 {
     completion_list *cur = comp_list;
 
@@ -400,7 +400,7 @@ inline int OutputCompletionList(void)
 
 /* Clean up */
 
-inline void FreeCompletionList(void)
+static inline void FreeCompletionList(void)
 {
     completion_list *cur = comp_list;
 
@@ -429,7 +429,7 @@ inline void FreeCompletionList(void)
 
 /* Add the members of a compound to the completion list */
 
-inline int AddCompoundMembers(xmlNodePtr compound,
+static inline int AddCompoundMembers(xmlNodePtr compound,
                               const char *name, const char *url)
 {
     xmlNodePtr child = compound->xmlChildrenNode;
