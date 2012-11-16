$NetBSD: patch-src_lxt2__read.c,v 1.2 2012/11/16 00:33:18 joerg Exp $

--- src/lxt2_read.c.orig	2006-01-27 15:43:58.000000000 +0000
+++ src/lxt2_read.c
@@ -62,8 +62,8 @@ _LXT2_RD_INLINE static unsigned int lxt2
 {
 unsigned short x = *((unsigned short *)((unsigned char *)mm+offset));
 
-  __asm("xchgb %b0,%h0" :
-        "=q" (x)        :
+  __asm("rorw $8, %w1" :
+        "=r" (x)        :
         "0" (x));
 
     return (unsigned int) x;
@@ -1113,7 +1113,7 @@ void lxt2_rd_close( struct lxt2_rd_trace
 /* 
  * return number of facs in trace
  */
-_LXT2_RD_INLINE lxtint32_t lxt2_rd_get_num_facs( struct lxt2_rd_trace* lt ) {
+lxtint32_t lxt2_rd_get_num_facs( struct lxt2_rd_trace* lt ) {
 
   return( lt ? lt->numfacs : 0 );
 
@@ -1195,7 +1195,7 @@ _LXT2_RD_INLINE lxtint32_t lxt2_rd_get_f
 
 }
 
-_LXT2_RD_INLINE lxtint32_t lxt2_rd_get_alias_root(struct lxt2_rd_trace *lt, lxtint32_t facidx) {
+lxtint32_t lxt2_rd_get_alias_root(struct lxt2_rd_trace *lt, lxtint32_t facidx) {
 
   if( lt && (facidx < lt->numfacs) ) {
 
@@ -1376,7 +1376,7 @@ _LXT2_RD_INLINE int lxt2_rd_clr_fac_proc
 
 }
 
-_LXT2_RD_INLINE int lxt2_rd_set_fac_process_mask_all( struct lxt2_rd_trace* lt ) {
+int lxt2_rd_set_fac_process_mask_all( struct lxt2_rd_trace* lt ) {
 
   int rc = 0;
 
@@ -1407,7 +1407,7 @@ _LXT2_RD_INLINE int lxt2_rd_clr_fac_proc
 /*
  * block memory set/get used to control buffering
  */
-_LXT2_RD_INLINE lxtint64_t lxt2_rd_set_max_block_mem_usage( struct lxt2_rd_trace* lt, lxtint64_t block_mem_max ) {
+lxtint64_t lxt2_rd_set_max_block_mem_usage( struct lxt2_rd_trace* lt, lxtint64_t block_mem_max ) {
 
   lxtint64_t rc = lt->block_mem_max;
 
