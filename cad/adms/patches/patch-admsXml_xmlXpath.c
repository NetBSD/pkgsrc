$NetBSD: patch-admsXml_xmlXpath.c,v 1.1 2012/05/05 22:14:42 dholland Exp $

Patch up gcc inline semantics.

--- admsXml/xmlXpath.c~	2007-04-19 12:44:04.000000000 +0000
+++ admsXml/xmlXpath.c
@@ -1860,10 +1860,10 @@ _t_goto_parse(parse_unary)
 
 /*admstpathevaluate*/
 
-#define _t_goto_evaluate_local(function) inline p_admstpathevaluate (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst)
-#define _t_goto_evaluate(function) inline void (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst)
-#define _t_goto_evaluate_location(function) inline void (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst,p_slist *mynewlocationptr)
-#define _t_goto_evaluate_binary(function) inline void (function) (p_admstpathevaluate myadmstpathevaluate,p_slist mylocation,p_admst mycuradmst)
+#define _t_goto_evaluate_local(function) static inline p_admstpathevaluate (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst)
+#define _t_goto_evaluate(function) static inline void (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst)
+#define _t_goto_evaluate_location(function) static inline void (function)(p_admstpathevaluate myadmstpathevaluate,p_admst mycuradmst,p_slist *mynewlocationptr)
+#define _t_goto_evaluate_binary(function) static inline void (function) (p_admstpathevaluate myadmstpathevaluate,p_slist mylocation,p_admst mycuradmst)
 _t_goto_evaluate(admstpathevaluate_admstroot);
 _t_goto_evaluate_local(admstpathevaluate_local_admstroot);
 _t_goto_evaluate(admstpathevaluate_admstpath);
@@ -2190,7 +2190,7 @@ _t_goto_evaluate_local(admstpathevaluate
   return mynewadmstpathevaluate;
 }
 
-inline void code1 (char**mytext,p_admstpathevaluate myadmstpathevaluate,p_admst mypreviousadmst)
+static inline void code1 (char**mytext,p_admstpathevaluate myadmstpathevaluate,p_admst mypreviousadmst)
 {
   p_slist mynewlocation=NULL;
   admstpathevaluate_location(myadmstpathevaluate,mypreviousadmst,&mynewlocation);
