# $NetBSD: hacks.mk,v 1.2 2019/11/03 19:04:08 rillig Exp $

.if !defined(SPIDERMONKEY52_HACKS_MK)
SPIDERMONKEY52_HACKS_MK=	# defined

###
### TLS is not supported yet on NetBSD aarch64 as of 8.99.22
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64*)
PKG_HACKS+=	tls
CONFIGURE_ENV+=	ac_cv_thread_keyword=no
.endif

.endif  # SPIDERMONKEY52_HACKS_MK
