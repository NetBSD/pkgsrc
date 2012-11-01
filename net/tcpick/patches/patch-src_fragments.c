$NetBSD: patch-src_fragments.c,v 1.1 2012/11/01 19:35:20 joerg Exp $

--- src/fragments.c.orig	2012-10-30 21:54:50.000000000 +0000
+++ src/fragments.c
@@ -83,7 +83,7 @@
                         * list = ( * list )->next;      \
                         FREE_FR (tmp)                   \
                         }
-__inline__ int 
+int 
 addfr( struct FRAGMENT ** first,
        int wlen,
        u_int32_t data_off,
@@ -156,7 +156,7 @@ addfr( struct FRAGMENT ** first,
 	}
 }
 
-__inline__ int
+int
 flush_ack ( struct HOST_DESC * desc,
 	    struct CONN * conn_ptr,
 	    int ack_num )
