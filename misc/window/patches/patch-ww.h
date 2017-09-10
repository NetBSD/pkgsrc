$NetBSD: patch-ww.h,v 1.1 2017/09/10 01:00:01 dholland Exp $

Signedness fixes: the sign bit of fmap is used in bit operations and
causes compiler warnings and build failures, so make it unsigned.

--- ww.h~	2011-09-06 18:46:21.000000000 +0000
+++ ww.h
@@ -104,7 +104,7 @@ struct ww {
 		/* arrays */
 	char **ww_win;		/* the window */
 	union ww_char **ww_buf;	/* the buffer */
-	char **ww_fmap;		/* map for frame and box windows */
+	unsigned char **ww_fmap;		/* map for frame and box windows */
 	short *ww_nvis;		/* how many ww_buf chars are visible per row */
 
 		/* information for wwwrite() and company */
@@ -341,7 +341,7 @@ const char *
 	wwerror(void);
 void	wwflush(void);
 void	wwframe(struct ww *, struct ww *);
-void	wwframec(struct ww *, int, int, char);
+void	wwframec(struct ww *, int, int, unsigned char);
 void	wwfree(char **, int);
 int	wwgetpty(struct ww *);
 int	wwgettty(int, struct ww_tty *);
