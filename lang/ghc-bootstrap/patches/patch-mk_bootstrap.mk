$NetBSD: patch-mk_bootstrap.mk,v 1.1 2013/12/15 02:00:07 dholland Exp $

--- mk/bootstrap.mk~	2008-06-16 17:27:16.000000000 +0000
+++ mk/bootstrap.mk
@@ -145,7 +145,7 @@ ifeq "$(GhcWithInterpreter)" "YES"
 HC_BOOT_LIBS += -lHSreadline -lHStemplate-haskell -lHSunix -lHSunix_cbits
 endif
 
-HC_BOOT_LIBS +=  -lHSregex-compat -lHSregex-posix -lHSregex-base -lHSCabal -lHShaskell98 -lHSbase -lHSbase_cbits -lHSparsec -lHSrts -lgmp -lm -lrt $(EXTRA_HC_BOOT_LIBS)
+HC_BOOT_LIBS +=  -lHSregex-compat -lHSregex-posix -lHSregex-base -lHSCabal -lHShaskell98 -lHSbase -lHSbase_cbits -lHSparsec -lHSrts -Wl,-R@PREFIX@/lib -L@PREFIX@/lib -lgmp -lm -lrt $(EXTRA_HC_BOOT_LIBS)
 
 ifeq "$(GhcLibsWithReadline)" "YES"
 HC_BOOT_LIBS += $(patsubst %, -l%, $(LibsReadline))
