$NetBSD: patch-ghc.mk,v 1.1 2013/12/12 12:47:17 obache Exp $

We want bootstrapping bindists to be as small as possible, and bzip2
is not enough:

  % du -sh ghc-*.tar*
  291M    ghc-7.6.2-boot-powerpc-apple-darwin.tar
   60M    ghc-7.6.2-boot-powerpc-apple-darwin.tar.bz2
   32M    ghc-7.6.2-boot-powerpc-apple-darwin.tar.xz


--- ghc.mk.orig	2013-02-14 02:24:35.000000000 +0000
+++ ghc.mk
@@ -1009,7 +1009,8 @@ unix-binary-dist-prep:
 	$(call removeFiles,$(BIN_DIST_PREP_TAR))
 # h means "follow symlinks", e.g. if aclocal.m4 is a symlink to a source
 # tree then we want to include the real file, not a symlink to it
-	cd bindistprep && "$(TAR_CMD)" hcf - -T ../$(BIN_DIST_LIST) | bzip2 -c > ../$(BIN_DIST_PREP_TAR_BZ2)
+	"$(MKDIRHIER)" compiler/stage2/doc # Workaround needed when building no docs.
+	cd bindistprep && "$(TAR_CMD)" hcf ../$(BIN_DIST_PREP_TAR) -T ../$(BIN_DIST_LIST)
 
 windows-binary-dist-prep:
 	$(call removeTrees,bindistprep/)
