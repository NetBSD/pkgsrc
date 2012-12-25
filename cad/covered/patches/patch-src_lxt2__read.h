$NetBSD: patch-src_lxt2__read.h,v 1.1 2012/12/25 21:14:45 joerg Exp $

--- src/lxt2_read.h.orig	2012-12-25 15:00:05.000000000 +0000
+++ src/lxt2_read.h
@@ -247,12 +247,12 @@ unsigned process_mask_dirty : 1; /* only
 struct lxt2_rd_trace *       	lxt2_rd_init(const char *name);
 void                    	lxt2_rd_close(struct lxt2_rd_trace *lt);
 
-_LXT2_RD_INLINE lxtint64_t	lxt2_rd_set_max_block_mem_usage(struct lxt2_rd_trace *lt, lxtint64_t block_mem_max);
-_LXT2_RD_INLINE lxtint64_t	lxt2_rd_get_block_mem_usage(struct lxt2_rd_trace *lt);
+lxtint64_t	lxt2_rd_set_max_block_mem_usage(struct lxt2_rd_trace *lt, lxtint64_t block_mem_max);
+lxtint64_t	lxt2_rd_get_block_mem_usage(struct lxt2_rd_trace *lt);
 _LXT2_RD_INLINE unsigned int	lxt2_rd_get_num_blocks(struct lxt2_rd_trace *lt);
 unsigned int			lxt2_rd_get_num_active_blocks(struct lxt2_rd_trace *lt);
 
-_LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_num_facs(struct lxt2_rd_trace *lt);
+lxtint32_t	lxt2_rd_get_num_facs(struct lxt2_rd_trace *lt);
 char *				lxt2_rd_get_facname(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 struct lxt2_rd_geometry *	lxt2_rd_get_fac_geometry(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 _LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_fac_rows(struct lxt2_rd_trace *lt, lxtint32_t facidx);
@@ -260,7 +260,7 @@ _LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_f
 _LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_fac_lsb(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 _LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_fac_flags(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 _LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_fac_len(struct lxt2_rd_trace *lt, lxtint32_t facidx);
-_LXT2_RD_INLINE lxtint32_t	lxt2_rd_get_alias_root(struct lxt2_rd_trace *lt, lxtint32_t facidx);
+lxtint32_t	lxt2_rd_get_alias_root(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 
 _LXT2_RD_INLINE char		lxt2_rd_get_timescale(struct lxt2_rd_trace *lt);
 _LXT2_RD_INLINE lxtint64_t	lxt2_rd_get_start_time(struct lxt2_rd_trace *lt);
@@ -269,7 +269,7 @@ _LXT2_RD_INLINE lxtint64_t	lxt2_rd_get_e
 _LXT2_RD_INLINE int		lxt2_rd_get_fac_process_mask(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 _LXT2_RD_INLINE int		lxt2_rd_set_fac_process_mask(struct lxt2_rd_trace *lt, lxtint32_t facidx);
 _LXT2_RD_INLINE int		lxt2_rd_clr_fac_process_mask(struct lxt2_rd_trace *lt, lxtint32_t facidx);
-_LXT2_RD_INLINE int		lxt2_rd_set_fac_process_mask_all(struct lxt2_rd_trace *lt);
+int		lxt2_rd_set_fac_process_mask_all(struct lxt2_rd_trace *lt);
 _LXT2_RD_INLINE int		lxt2_rd_clr_fac_process_mask_all(struct lxt2_rd_trace *lt);
 
 				/* null value_change_callback calls an empty dummy function */
