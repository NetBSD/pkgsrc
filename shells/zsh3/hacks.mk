# $NetBSD: hacks.mk,v 1.2 2005/01/25 18:22:24 tv Exp $

.ifndef ZSH3_HACKS_MK
ZSH3_HACKS_MK=		# defined

### [Mon Jan 24 22:27:33 UTC 2005 : tv]
### for some reason, the GETPGRP_VOID test is not working correctly;
### also, ut_xtime (the obsolescent utmpx field) is changed
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=		compat
CONFIGURE_ENV+=		ac_cv_func_getpgrp_void=yes
CPPFLAGS+=		-Dut_xtime=ut_tv.tv_sec
.endif

.endif
