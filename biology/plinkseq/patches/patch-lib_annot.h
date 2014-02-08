$NetBSD: patch-lib_annot.h,v 1.1 2014/02/08 12:27:14 wiedi Exp $

rename to avoid collision on sunos
--- lib/annot.h.orig	2012-03-19 11:35:59.000000000 +0000
+++ lib/annot.h
@@ -35,7 +35,7 @@ enum seq_annot_t { UNDEF   =  0 ,     //
 		   ESPLICE5 =  27 ,    // Essential 5' splice-site
                    ESPLICE3 =  28 ,    // Essential 3' splice-site
  		   NON      =  24 ,    // nonsense allele		   		  
- 		   FS       =  25 ,    // frameshift 
+ 		   FS_       =  25 ,    // frameshift 
 		   RT       =  26 };   // readthrough
 
 struct SeqInfo { 
