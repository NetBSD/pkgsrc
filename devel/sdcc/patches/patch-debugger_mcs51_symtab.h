$NetBSD: patch-debugger_mcs51_symtab.h,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- debugger/mcs51/symtab.h.orig	2025-12-18 05:32:23.483299460 +0000
+++ debugger/mcs51/symtab.h
@@ -106,13 +106,13 @@ typedef struct declarator {
     short    num_elem;     /* # of elems if type==array  */
     short    ptr_const :1;   /* pointer is constant        */
     short    ptr_volatile:1; /* pointer is volatile        */
-    struct link *tspec;     /* pointer type specifier      */
+    struct linkt *tspec;     /* pointer type specifier      */
 } declarator ;
 
 #define DECLARATOR   0
 #define SPECIFIER    1
 
-typedef struct link {
+typedef struct linkt {
     unsigned class : 1      ;  /* DECLARATOR or SPECIFIER    */
     unsigned tdef  : 1      ;  /* current link created by    */
     /* typedef if this flag is set*/
@@ -121,8 +121,8 @@ typedef struct link {
         declarator     d     ;  /* if CLASS == DECLARATOR     */
     } select ;
 
-    struct link    *next    ;  /* next element on the chain  */
-} link ;
+    struct linkt    *next    ;  /* next element on the chain  */
+} linkt_t ;
 
 typedef struct symbol {
     char     *name               ;
@@ -136,8 +136,8 @@ typedef struct symbol {
     unsigned addr               ;  /* address if the symbol */
     unsigned eaddr              ;  /* end address for functions */
     char     addr_type          ;  /* which address space   */
-    link     *type              ;  /* start of type chain        */
-    link     *etype             ;  /* end of type chain          */
+    linkt_t  *type              ;  /* start of type chain        */
+    linkt_t  *etype             ;  /* end of type chain          */
     char     scopetype         ;  /* 'G' global, 'F' - file, 'L' local */
     char     *sname             ;  /* if 'F' or 'L' then scope name */
     char     *rname             ;  /* real name i.e. mangled beyond recognition */
@@ -242,6 +242,6 @@ symbol *symLookup (char *,context *);
 DEFSETFUNC(moduleWithName);
 DEFSETFUNC(moduleWithCName);
 DEFSETFUNC(moduleWithAsmName);
-unsigned int getSize (link *);
+unsigned int getSize (linkt_t *);
 
 #endif
