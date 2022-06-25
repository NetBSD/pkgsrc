$NetBSD: patch-tool_lemon.c,v 1.3 2022/06/25 09:35:52 he Exp $

Avoid either undefined or implementation defined behaviour,
by making the base hash variable unsigned, so that we avoid
it ever going negative (as it did on powerpc).

Just adopt & apply https://sqlite.org/src/info/8d399a03de63c159

--- tool/lemon.c.orig	2005-04-23 22:43:22.000000000 +0000
+++ tool/lemon.c
@@ -3016,7 +3016,7 @@ int mhflag;                 /* True if g
   int maxdtlength;          /* Maximum length of any ".datatype" field. */
   char *stddt;              /* Standardized name for a datatype */
   int i,j;                  /* Loop counters */
-  int hash;                 /* For hashing the name of a type */
+  unsigned hash;            /* For hashing the name of a type */
   char *name;               /* Name of the parser */
 
   /* Allocate and initialize types[] and allocate stddt[] */
@@ -3711,10 +3711,10 @@ char *s2;
 ** Code for processing tables in the LEMON parser generator.
 */
 
-PRIVATE int strhash(x)
+PRIVATE unsigned strhash(x)
 char *x;
 {
-  int h = 0;
+  unsigned h = 0;
   while( *x) h = h*13 + *(x++);
   return h;
 }
@@ -3786,8 +3786,8 @@ int Strsafe_insert(data)
 char *data;
 {
   x1node *np;
-  int h;
-  int ph;
+  unsigned h;
+  unsigned ph;
 
   if( x1a==0 ) return 0;
   ph = strhash(data);
@@ -3842,7 +3842,7 @@ char *data;
 char *Strsafe_find(key)
 char *key;
 {
-  int h;
+  unsigned h;
   x1node *np;
 
   if( x1a==0 ) return 0;
@@ -3949,8 +3949,8 @@ struct symbol *data;
 char *key;
 {
   x2node *np;
-  int h;
-  int ph;
+  unsigned h;
+  unsigned ph;
 
   if( x2a==0 ) return 0;
   ph = strhash(key);
@@ -4007,7 +4007,7 @@ char *key;
 struct symbol *Symbol_find(key)
 char *key;
 {
-  int h;
+  unsigned h;
   x2node *np;
 
   if( x2a==0 ) return 0;
@@ -4084,10 +4084,10 @@ struct config *b;
 }
 
 /* Hash a state */
-PRIVATE int statehash(a)
+PRIVATE unsigned statehash(a)
 struct config *a;
 {
-  int h=0;
+  unsigned h=0;
   while( a ){
     h = h*571 + a->rp->index*37 + a->dot;
     a = a->bp;
@@ -4155,8 +4155,8 @@ struct state *data;
 struct config *key;
 {
   x3node *np;
-  int h;
-  int ph;
+  unsigned h;
+  unsigned ph;
 
   if( x3a==0 ) return 0;
   ph = statehash(key);
@@ -4213,7 +4213,7 @@ struct config *key;
 struct state *State_find(key)
 struct config *key;
 {
-  int h;
+  unsigned h;
   x3node *np;
 
   if( x3a==0 ) return 0;
@@ -4243,10 +4243,10 @@ struct state **State_arrayof()
 }
 
 /* Hash a configuration */
-PRIVATE int confighash(a)
+PRIVATE unsigned confighash(a)
 struct config *a;
 {
-  int h=0;
+  unsigned h=0;
   h = h*571 + a->rp->index*37 + a->dot;
   return h;
 }
@@ -4300,8 +4300,8 @@ int Configtable_insert(data)
 struct config *data;
 {
   x4node *np;
-  int h;
-  int ph;
+  unsigned h;
+  unsigned ph;
 
   if( x4a==0 ) return 0;
   ph = confighash(data);
