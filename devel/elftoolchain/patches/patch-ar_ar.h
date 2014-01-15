$NetBSD: patch-ar_ar.h,v 1.1 2014/01/15 13:50:43 joerg Exp $

--- ar/ar.h.orig	2014-01-12 00:07:52.000000000 +0000
+++ ar/ar.h
@@ -135,8 +135,14 @@ struct bsdar {
 	TAILQ_HEAD(, ar_obj) v_obj;	/* object(member) list */
 };
 
+#if defined(__GNUC__) && __GNUC__ >= 2
+__attribute__((__format__(__printf__, 3, 4)))
+#endif
 void	bsdar_errc(struct bsdar *, int _code, const char *fmt, ...);
 int	bsdar_is_pseudomember(struct bsdar *_ar, const char *_name);
+#if defined(__GNUC__) && __GNUC__ >= 2
+__attribute__((__format__(__printf__, 3, 4)))
+#endif
 void	bsdar_warnc(struct bsdar *, int _code, const char *fmt, ...);
 const char *bsdar_strmode(mode_t m);
 void	ar_mode_d(struct bsdar *bsdar);
