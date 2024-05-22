$NetBSD: patch-acls.c,v 1.1 2024/05/22 09:49:36 bouyer Exp $

Properly handle EOPNOTSUPP

--- acls.c.orig	2024-05-22 11:29:32.963825978 +0200
+++ acls.c	2024-05-22 11:30:07.507590619 +0200
@@ -1101,6 +1101,9 @@
 #ifdef ENOTSUP
 		case ENOTSUP:
 #endif
+#ifdef EOPNOTSUPP
+		case EOPNOTSUPP:
+#endif
 		case ENOSYS:
 			/* No ACLs are available. */
 			break;
