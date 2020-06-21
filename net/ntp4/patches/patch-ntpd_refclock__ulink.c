$NetBSD: patch-ntpd_refclock__ulink.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_ulink.c.orig	2012-06-28 06:37:06.000000000 +0000
+++ ntpd/refclock_ulink.c
@@ -389,6 +389,7 @@ ulink_receive(
                     }
 		    break;
 		}
+		/*FALLTHROUGH*/
 
 		case LEN320:
 
@@ -433,6 +434,7 @@ ulink_receive(
 		}
 
 		default:
+		/*FALLTHROUGH*/
 		refclock_report(peer, CEVNT_BADREPLY);
 		return;
 	}
