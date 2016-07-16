$NetBSD: patch-agen5_fmemopen.c,v 1.2 2016/07/16 20:00:14 wiz Exp $

NetBSD portability fix.

--- agen5/fmemopen.c.orig	2011-06-26 14:39:38.000000000 +0000
+++ agen5/fmemopen.c
@@ -61,13 +61,13 @@ typedef struct {
    typedef int       seek_ret_t;
 
 #elif defined(HAVE_FUNOPEN)
-   typedef fpos_t  seek_off_t;
-   typedef fpos_t  seek_ret_t;
+   typedef off_t  seek_off_t;
+   typedef off_t  seek_ret_t;
 
 #  ifdef NEED_COOKIE_FUNCTION_TYPEDEFS
      typedef int     (cookie_read_function_t )(void *, char *, int);
      typedef int     (cookie_write_function_t)(void *, char const *, int);
-     typedef fpos_t  (cookie_seek_function_t )(void *, fpos_t, int);
+     typedef off_t  (cookie_seek_function_t )(void *, off_t, int);
      typedef int     (cookie_close_function_t)(void *);
 #  endif /* NEED_COOKIE_FUNCTION_TYPEDEFS */
 #endif
