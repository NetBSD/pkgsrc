# $NetBSD: buildlink2.mk,v 1.5 2004/02/14 21:54:12 jmmv Exp $

.if !defined(PKGCONFIG_BUILDLINK2_MK)
PKGCONFIG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pkgconfig
BUILDLINK_DEPENDS.pkgconfig?=	pkgconfig>=0.15.0
BUILDLINK_PKGSRCDIR.pkgconfig?=	../../devel/pkgconfig
BUILDLINK_DEPMETHOD.pkgconfig?=	build

PKG_CONFIG_PATH?=	${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig
CONFIGURE_ENV+=		PKG_CONFIG="${BUILDLINK_DEPENDS.pkgconfig}/bin/pkg-config"
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${PKG_CONFIG_PATH}"
MAKE_ENV+=		PKG_CONFIG="${BUILDLINK_DEPENDS.pkgconfig}/bin/pkg-config"
MAKE_ENV+=		PKG_CONFIG_PATH="${PKG_CONFIG_PATH}"

.endif	# PKGCONFIG_BUILDLINK2_MK
