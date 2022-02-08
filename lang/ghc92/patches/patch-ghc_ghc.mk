$NetBSD: patch-ghc_ghc.mk,v 1.2 2022/02/08 07:45:02 pho Exp $

The stage-0 compiler isn't guaranteed to have an event-logging RTS.
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/7518

--- ghc/ghc.mk.orig	2022-01-21 03:38:06.464699891 +0000
+++ ghc/ghc.mk
@@ -76,6 +76,11 @@ else
 ghc_stage1_CONFIGURE_OPTS += -f-threaded
 endif
 
+# Same for an event-logging RTS.
+ifeq "$(GhcEventLoggingRts)" "NO"
+ghc_stage1_CONFIGURE_OPTS += -f-eventlog
+endif
+
 ifeq "$(GhcProfiled)" "YES"
 ghc_stage2_PROGRAM_WAY = p
 endif
