# $NetBSD: hacks.mk,v 1.1 2021/09/06 06:59:06 nia Exp $

.if !defined(DAV1D_HACKS_MK)
DAV1D_HACKS_MK=	# defined

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[5678].*)
PKG_HACKS+=	disable-tests

# checkasm test fails to link
MESON_ARGS+=	-Denable_tests=false
.endif

.endif	# DAV1D_HACKS_MK
