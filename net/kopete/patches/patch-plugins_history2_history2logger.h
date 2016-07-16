$NetBSD: patch-plugins_history2_history2logger.h,v 1.1 2016/07/16 01:17:59 markd Exp $

gcc6 fix

--- plugins/history2/history2logger.h.orig	2015-12-06 12:54:22.000000000 +0000
+++ plugins/history2/history2logger.h
@@ -94,7 +94,7 @@ public:
 	 * from Kopete::Contact @param c in the given @param sens
 	 */
 	QList<Kopete::Message> readMessages(int lines,
-	                                    int offset=0, const Kopete::MetaContact *c=false, bool reverseOrder=true);
+	                                    int offset=0, const Kopete::MetaContact *c=0, bool reverseOrder=true);
 
 	/**
 	 * Same as the following, but for one date. I did'nt reuse the above function
