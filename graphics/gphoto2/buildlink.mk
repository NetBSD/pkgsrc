# $NetBSD: buildlink.mk,v 1.2 2002/09/10 16:06:42 wiz Exp $
#
# This Makefile fragment is included by packages that use gphoto2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gphoto2 to the dependency pattern
#     for the version of gphoto2 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(GPHOTO2_BUILDLINK_MK)
GPHOTO2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gphoto2?=	gphoto>=2.1.0nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gphoto2}:../../graphics/gphoto2

EVAL_PREFIX+=		BUILDLINK_PREFIX.gphoto2=gphoto2
BUILDLINK_PREFIX.gphoto2=	${LOCALBASE}
BUILDLINK_FILES.gphoto2=	include/gphoto2/*.h
BUILDLINK_FILES.gphoto2+=	lib/libgphoto2.*
BUILDLINK_FILES.gphoto2+=	lib/libgphoto2_port.*

BUILDLINK_TARGETS.gphoto2=	gphoto2-buildlink
BUILDLINK_TARGETS.gphoto2+=	gphoto2-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gphoto2}

BUILDLINK_CONFIG.gphoto2=	\
			${BUILDLINK_PREFIX.gphoto2}/bin/gphoto2-config
BUILDLINK_CONFIG_WRAPPER.gphoto2=	\
	 		${BUILDLINK_DIR}/bin/gphoto2-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gphoto2}|${BUILDLINK_CONFIG.gphoto2}|g"

.if defined(USE_CONFIG_WRAPPER)
GPHOTO2_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gphoto2}
CONFIGURE_ENV+=		GPHOTO2_CONFIG="${GPHOTO2_CONFIG}"
MAKE_ENV+=		GPHOTO2_CONFIG="${GPHOTO2_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gphoto2}
gphoto2-buildlink: _BUILDLINK_USE
gphoto2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GPHOTO2_BUILDLINK_MK
