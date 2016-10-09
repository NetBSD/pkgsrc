$NetBSD: patch-lib_include_vmci__sockets.h,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/include/vmci_sockets.h.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/include/vmci_sockets.h
@@ -837,7 +837,7 @@ struct uuid_2_cid {
       return io.u2c_context_id;
    }
 #  endif // __KERNEL__
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
    /*
     * No FreeBSD support yet, but it might appear in the future. Just define
     * some stubs that return errors - that way a client doesn't have to ifdef
