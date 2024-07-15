$NetBSD: patch-acls.c,v 1.2 2024/07/15 17:20:03 hauke Exp $

Properly handle EOPNOTSUPP

--- acls.c.orig	2022-09-11 17:04:26.000000000 +0000
+++ acls.c
@@ -1101,6 +1101,9 @@ int default_perms_for_dir(const char *dir)
 #ifdef ENOTSUP
 		case ENOTSUP:
 #endif
+#if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
+		case EOPNOTSUPP:
+#endif
 		case ENOSYS:
 			/* No ACLs are available. */
 			break;
