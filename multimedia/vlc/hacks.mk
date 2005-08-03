# $NetBSD: hacks.mk,v 1.1 2005/08/03 04:18:31 grant Exp $

# the autoconf test for the Darwin linker wrongly succeeds when using
# icc/Linux because icc ignores unknown flags. override this brain
# damage.
.if ${OPSYS} != "Darwin"
CONFIGURE_ENV+=		ac_cv_ld_darwin=no
.endif
