# $NetBSD: buildlink.mk,v 1.1 2002/03/20 15:50:02 jlam Exp $
#
# This Makefile fragment is included by packages that use pkgconfig.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pkgconfig to the dependency pattern
#     for the version of pkgconfig desired.
# (2) Include this Makefile fragment in the package Makefile,

.if !defined(PKGCONFIG_BUILDLINK_MK)
PKGCONFIG_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.pkgconfig?=	pkgconfig-[0-9]*
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.pkgconfig}:../../devel/pkgconfig

EVAL_PREFIX+=		BUILDLINK_PREFIX.pkgconfig=pkgconfig
BUILDLINK_PREFIX.pkgconfig_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS.pkgconfig=	pkgconfig-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pkgconfig}

BUILDLINK_CONFIG.pkgconfig=	\
	${BUILDLINK_PREFIX.pkgconfig}/bin/pkg-config
BUILDLINK_CONFIG_WRAPPER.pkgconfig=	\
	${BUILDLINK_DIR}/bin/pkg-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.pkgconfig}|${BUILDLINK_CONFIG.pkgconfig}|g"

.if defined(USE_CONFIG_WRAPPER)
PKG_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.pkgconfig}
PKG_CONFIG_PATH?=	${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig
CONFIGURE_ENV+=		PKG_CONFIG="${PKG_CONFIG}"
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${PKG_CONFIG_PATH}"
MAKE_ENV+=		PKG_CONFIG="${PKG_CONFIG}"
MAKE_ENV+=		PKG_CONFIG_PATH="${PKG_CONFIG_PATH}"
.endif

pre-configure: ${BUILDLINK_TARGETS.pkgconfig}
pkgconfig-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# PKGCONFIG_BUILDLINK_MK
