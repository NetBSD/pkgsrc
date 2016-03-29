$NetBSD: patch-Engine_entry1.c,v 1.1 2016/03/29 22:06:48 joerg Exp $

--- Engine/entry1.c.orig	2016-03-28 17:51:03.964243385 +0000
+++ Engine/entry1.c
@@ -1084,7 +1084,7 @@ OENTRY opcodlst_1[] = {
     (SUBR) chnset_opcode_init_a, (SUBR) NULL, (SUBR) notinit_opcode_stub },
   { "chnset.S",    S(CHNGET),0,           3,      "",             "SS",
     (SUBR) chnset_opcode_init_S, (SUBR) chnset_opcode_perf_S, (SUBR) NULL },
-  { "chnmix",      S(CHNGET),           CB, 5,      "",             "aS",
+  { "chnmix",      S(CHNGET),           CSOUND_CB, 5,      "",             "aS",
     (SUBR) chnmix_opcode_init, (SUBR) NULL, (SUBR) notinit_opcode_stub  },
   { "chnclear",    S(CHNCLEAR),        CW, 5,      "",             "S",
     (SUBR) chnclear_opcode_init, (SUBR) NULL, (SUBR) notinit_opcode_stub },
