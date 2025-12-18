$NetBSD: patch-debugger_mcs51_cmd.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- debugger/mcs51/cmd.c.orig	2025-12-18 05:35:54.317552347 +0000
+++ debugger/mcs51/cmd.c
@@ -327,8 +327,8 @@ static char *warranty=
 "POSSIBILITY OF SUCH DAMAGES.\n";
 #endif
 
-static void printTypeInfo(link *);
-static void printValAggregates (symbol *,link *,char,unsigned int,int);
+static void printTypeInfo(linkt_t *);
+static void printValAggregates (symbol *,linkt_t *,char,unsigned int,int);
 static  int printOrSetSymValue (symbol *sym, context *cctxt,
                                 int flg, int dnum, int fmt,
                                 char *rs, char *val, char cmp);
@@ -2323,7 +2323,7 @@ int cmdListSrc (char *s, context *cctxt)
     return 0;
 }
 
-static unsigned long getValBasic(symbol *sym, link *type, char *val)
+static unsigned long getValBasic(symbol *sym, linkt_t *type, char *val)
 {
     char *s;
     union
@@ -2347,7 +2347,7 @@ static unsigned long getValBasic(symbol 
     {
             if (IS_INTEGRAL(type))
         {
-            link *etype;
+            linkt_t *etype;
             if ( type->next )
                 etype = type->next;
             else
@@ -2460,7 +2460,7 @@ static void printFmtInteger(char *deffmt
 /*-----------------------------------------------------------------*/
 /* printValBasic - print value of basic types                      */
 /*-----------------------------------------------------------------*/
-static void printValBasic(symbol *sym, link *type,
+static void printValBasic(symbol *sym, linkt_t *type,
                           char mem, unsigned addr,int size, int fmt)
 {
     union {
@@ -2484,7 +2484,7 @@ static void printValBasic(symbol *sym, l
         else
         if (IS_INTEGRAL(type))
         {
-            link *etype;
+            linkt_t *etype;
             if ( type->next )
                 etype = type->next;
             else
@@ -2534,10 +2534,10 @@ static void printValFunc (symbol *sym, i
 /*-----------------------------------------------------------------*/
 /* printArrayValue - will print the values of array elements       */
 /*-----------------------------------------------------------------*/
-static void printArrayValue (symbol *sym,  link *type,
+static void printArrayValue (symbol *sym,  linkt_t *type,
                              char space, unsigned int addr, int fmt)
 {
-        link *elem_type = type->next;
+        linkt_t *elem_type = type->next;
         int i;
 
         fprintf(stdout,"{");
@@ -2558,7 +2558,7 @@ static void printArrayValue (symbol *sym
 /*-----------------------------------------------------------------*/
 /* printStructValue - prints structures elements                   */
 /*-----------------------------------------------------------------*/
-static void printStructValue (symbol *sym, link *type,
+static void printStructValue (symbol *sym, linkt_t *type,
                               char space, unsigned int addr, int fmt)
 {
         symbol *fields = SPEC_STRUCT(type)->fields;
@@ -2581,7 +2581,7 @@ static void printStructValue (symbol *sy
 /*-----------------------------------------------------------------*/
 /* printValAggregates - print value of aggregates                  */
 /*-----------------------------------------------------------------*/
-static void printValAggregates (symbol *sym, link *type,
+static void printValAggregates (symbol *sym, linkt_t *type,
                                 char space,unsigned int addr, int fmt)
 {
 
@@ -2606,7 +2606,7 @@ static int printOrSetSymValue (symbol *s
     static char fmtChar[] = " todx ";
     static int stack = 1;
         symbol *fields;
-    link *type;
+    linkt_t *type;
     unsigned int  addr;
     int size, n;
     char *s, *s2;
@@ -2808,7 +2808,7 @@ static void printStructInfo (structdef *
 /*-----------------------------------------------------------------*/
 /* printTypeInfo - print out the type information                  */
 /*-----------------------------------------------------------------*/
-static void printTypeInfo(link *p)
+static void printTypeInfo(linkt_t *p)
 {
     if (!p)
         return ;
