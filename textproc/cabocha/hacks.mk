# $NetBSD: hacks.mk,v 1.2 2019/11/04 21:43:33 rillig Exp $

.if !defined(CABOCHA_HACKS_MK)
CABOCHA_HACKS_MK=	# defined

# No TLS support on NetBSD<6
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5].*-*)
PKG_HACKS+=			netbsd5-disable_tls
SUBST_CLASSES+=			disable_tls
SUBST_STAGE.disable_tls=	pre-configure
SUBST_FILES.disable_tls=	configure
SUBST_SED.disable_tls=		-e 's/enable_tls=yes/enable_tls=no/'
.endif

.endif
