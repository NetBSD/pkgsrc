$NetBSD: patch-util_IMdkit_i18nPtHdr.c,v 1.1 2024/06/15 08:51:04 tsutsui Exp $

- disable a change for upstream https://github.com/ibus/ibus/issues/2560
  because this sync() call makes all inputs extremely slower during
  IME enabled on at least NetBSD/i386 10.0.

--- util/IMdkit/i18nPtHdr.c.orig	2024-06-15 08:35:06.196322428 +0000
+++ util/IMdkit/i18nPtHdr.c
@@ -1757,7 +1757,9 @@ static void ProcessQueue (XIMS ims, CARD
         switch (hdr->major_opcode)
         {
         case XIM_FORWARD_EVENT:
+#if 0	/* XXX: disable fix for #2560 for a certain environments */
             sync();
+#endif
             ForwardEventMessageProc(ims, &call_data, p1);
             break;
         }
