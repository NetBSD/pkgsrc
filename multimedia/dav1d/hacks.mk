# $NetBSD: hacks.mk,v 1.2 2022/05/05 08:25:59 nia Exp $

.if !defined(DAV1D_HACKS_MK)
DAV1D_HACKS_MK=	# defined

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
PKG_HACKS+=	disable-tests

# checkasm test fails to link
MESON_ARGS+=	-Denable_tests=false
.endif

.endif	# DAV1D_HACKS_MK
