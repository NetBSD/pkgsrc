$NetBSD: patch-src_do.c,v 1.1 2015/06/18 01:58:30 dholland Exp $

avoid gccism (from PR 46354)

--- src/do.c~	2009-03-08 16:27:56.000000000 +0000
+++ src/do.c
@@ -2846,7 +2846,7 @@ for (ptr = VPKG; ptr != NULL; ptr=ptr->n
 
    ExpandVarstring(ptr->name,name,"");
    
-   snprintf(lock,CF_BUFSIZE-1,"%s_%d_%s_%d_%s_%s", name, ptr->cmp, ptr->ver ? ptr->ver: "" ,ptr->action, ptr->defines ?: "", ptr->elsedef ?: "");
+   snprintf(lock,CF_BUFSIZE-1,"%s_%d_%s_%d_%s_%s", name, ptr->cmp, ptr->ver ? ptr->ver: "" ,ptr->action, ptr->defines ? ptr->defines : "", ptr->elsedef ? ptr->elsedef : "");
    
    if (!GetLock(ASUniqueName("packages"),CanonifyName(lock),ptr->ifelapsed,ptr->expireafter,VUQNAME,CFSTARTTIME))
       {
