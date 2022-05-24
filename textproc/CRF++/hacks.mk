# $NetBSD: hacks.mk,v 1.3 2022/05/24 09:53:02 nia Exp $

.if !defined(CRFPP_HACKS_MK)
CRFPP_HACKS_MK=	# defined

# No TLS support on NetBSD<6
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 060000
PKG_HACKS+=			netbsd5-disable_tls
SUBST_CLASSES+=			disable_tls
SUBST_STAGE.disable_tls=	pre-configure
SUBST_FILES.disable_tls=	configure
SUBST_SED.disable_tls=		-e 's/enable_tls=yes/enable_tls=no/'
.endif

.endif
