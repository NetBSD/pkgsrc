$NetBSD: patch-libs_wine_ldt.c,v 1.1 2012/05/23 17:48:54 marino Exp $

--- libs/wine/ldt.c.orig	2011-08-05 17:24:22.000000000 +0000
+++ libs/wine/ldt.c
@@ -87,7 +87,8 @@ static inline int set_thread_area( struc
 #endif
 #endif
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+ || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #include <machine/segments.h>
 #include <machine/sysarch.h>
 #endif  /* __NetBSD__ || __FreeBSD__ || __OpenBSD__ */
@@ -175,7 +176,8 @@ static int internal_set_entry( unsigned
         if ((ret = modify_ldt(0x11, &ldt_info, sizeof(ldt_info))) < 0)
             perror( "modify_ldt" );
     }
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+   || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     {
 	LDT_ENTRY entry_copy = *entry;
 	/* The kernel will only let us set LDTs with user priority level */
