# $NetBSD: hacks.mk,v 1.1 2005/01/24 22:27:48 tv Exp $

.ifndef ZSH3_HACKS_MK
ZSH3_HACKS_MK=		# defined

### [Mon Jan 24 22:27:33 UTC 2005 : tv]
### For some reason, the GETPGRP_VOID test is not working correctly
###
.if ${OPSYS} == "Interix"
CONFIGURE_ENV+=		ac_cv_func_getpgrp_void=yes
.endif

.endif
