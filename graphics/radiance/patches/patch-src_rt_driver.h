$NetBSD: patch-src_rt_driver.h,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.

--- src/rt/driver.h~	2004-04-10 02:54:09.000000000 +0000
+++ src/rt/driver.h
@@ -20,7 +20,7 @@ typedef void dr_clearf_t(int, int);
 typedef void dr_paintrf_t(COLOR col, int xmin, int ymin, int xmax, int ymax);
 typedef int  dr_getcurf_t(int*,int*);
 typedef void dr_comoutf_t(char*);
-typedef void dr_cominf_t(char*,char*);
+typedef void dr_cominf_t(char*,size_t,char*);
 typedef void dr_flushf_t(void);
 
 struct driver {				/* driver functions */
@@ -212,9 +212,9 @@ extern char  dev_default[];		/* default 
  */
 
 					/* defined in editline.c */
-extern void	editline(char *buf, dr_getchf_t *c_get, dr_comoutf_t *s_put);
+extern void	editline(char *buf, size_t max, dr_getchf_t *c_get, dr_comoutf_t *s_put);
 extern void	tocombuf(char *b, struct driver *d);
-extern int	fromcombuf(char *b, struct driver *d);
+extern int	fromcombuf(char *b, size_t max, struct driver *d);
 
 					/* defined in devcomm.c */
 extern dr_initf_t slave_init; /* XXX should probably be in a seperate file */
