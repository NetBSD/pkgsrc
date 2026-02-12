$NetBSD: patch-pgp_seahorse-gpgme.c,v 1.1 2026/02/12 08:02:14 wiz Exp $

Fix build with gpgme 2.x.
https://gitlab.gnome.org/GNOME/seahorse/-/commit/aa68522cc696fa491ccfdff735b77bcf113168d0

--- pgp/seahorse-gpgme.c.orig	2026-02-12 07:59:16.091940233 +0000
+++ pgp/seahorse-gpgme.c
@@ -484,7 +484,9 @@ on_gpgme_event (void *user_data,
 		break;
 
 	case GPGME_EVENT_NEXT_KEY:
+#if GPGME_VERSION_NUMBER < 0x020000
 	case GPGME_EVENT_NEXT_TRUSTITEM:
+#endif
 	default:
 		/* Ignore unsupported event types */
 		break;
