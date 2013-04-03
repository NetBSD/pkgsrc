# $NetBSD: hacks.mk,v 1.2 2013/04/03 19:29:23 jmcneill Exp $

#
# Avoid -fkeep-inline-functions with NetBSD/arm
#
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm"
PKG_HACKS+=		netbsd-arm-stage1-fix
CONFIGURE_ARGS+=	--disable-bootstrap
.endif
