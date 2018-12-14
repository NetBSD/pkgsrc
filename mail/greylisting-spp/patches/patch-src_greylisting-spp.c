$NetBSD: patch-src_greylisting-spp.c,v 1.1 2018/12/14 07:19:39 schmonz Exp $

Log tuples if VERBOSE/DEBUG.

--- src/greylisting-spp.c.orig	2011-06-18 19:58:00.000000000 +0000
+++ src/greylisting-spp.c
@@ -144,18 +144,18 @@ int found, i;
 		       recipient);
     if (found < 0) {
 	/* No match found -> reject and add entry */
-	VERBOSE("Rejecting new triple")
+	VERBOSETUPLE("Rejecting new triple", remoteip, sender, recipient)
 	reject(sender);
 	add_entry(remoteip, ezmlm_sender == NULL ? sender : ezmlm_sender,
 		  recipient);
     } else if (found == 0) {
 	/* Match found, but min_reject is not expired -> reject again */
-	VERBOSE("Rejecting young triple")
+	VERBOSETUPLE("Rejecting young triple", remoteip, sender, recipient)
 	reject(sender);
     } else {
 	/* Match found and min_reject expired and max_wait or accept_good not
 	 * expired */
-	DEBUG("Accepting known triple")
+	DEBUGTUPLE("Accepting known triple", remoteip, sender, recipient)
 	if (!*sender) {
 	    /* Empty sender (bounce message) -> delete entry */
 	    delete_entry();
