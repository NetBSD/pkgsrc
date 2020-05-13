$NetBSD: patch-star_star.h,v 1.1 2020/05/13 08:21:49 micha Exp $

Fix for warning below on NetBSD (patch proposed by upstream).

|         ==> COMPILING "OBJ/x86_64-netbsd-gcc/acl_unix.o"
| In file included from acl_unix.c:82:0:
| star.h:850:0: warning: "toupper" redefined
|  #define toupper(c) (isupper(c) ? (c) : (c) - ('a' - 'A'))
| 
| In file included from /usr/include/ctype.h:97:0,
|                  from ../include/schily/ctype.h:33,
|                  from acl_unix.c:81:
| /usr/include/sys/ctype_inline.h:60:0: note: this is the location of the previous definition
|  #define toupper(c) ((int)((_toupper_tab_ + 1)[(c)]))

--- star/star.h.orig	2020-05-13 08:04:00.370176996 +0000
+++ star/star.h
@@ -841,6 +841,12 @@ typedef struct {
 #ifdef	isdigit
 #undef	isdigit		/* Needed for HP-UX */
 #endif
+#ifdef	isoctal
+#undef	isoctal         /* Needed if aclutils.h is present */
+#endif
+#ifdef	toupper
+#undef	toupper         /* Needed if aclutils.h is present */
+#endif
 #define	isdigit(c)	((c) >= '0' && (c) <= '9')
 #define	isoctal(c)	((c) >= '0' && (c) <= '7')
 #ifdef	isupper
