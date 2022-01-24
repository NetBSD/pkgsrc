$NetBSD: patch-amidi_amidi.c,v 1.1 2022/01/24 10:09:30 wiz Exp $

NetBSD does not provide CLOCK_MONOTONIC_RAW.

--- amidi/amidi.c.orig	2021-12-06 10:17:28.000000000 +0000
+++ amidi/amidi.c
@@ -536,8 +536,10 @@ int main(int argc, char *argv[])
 				cid = CLOCK_REALTIME;
 			else if (strcasecmp(optarg, "monotonic") == 0)
 				cid = CLOCK_MONOTONIC;
+#if defined(CLOCK_MONOTONIC_RAW)
 			else if (strcasecmp(optarg, "raw") == 0)
 				cid = CLOCK_MONOTONIC_RAW;
+#endif
 			else
 				error("Clock type not known");
 			break;
