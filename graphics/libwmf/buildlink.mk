# $NetBSD: buildlink.mk,v 1.7 2002/09/10 16:06:42 wiz Exp $
#
# This Makefile fragment is included by packages that use libwmf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libwmf to the dependency pattern
#     for the version of libwmf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBWMF_BUILDLINK_MK)
LIBWMF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libwmf?=	libwmf>=0.2.2nb2
BUILD_DEPENDS+=	${BUILDLINK_DEPENDS.libwmf}:../../graphics/libwmf

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwmf=libwmf
BUILDLINK_PREFIX.libwmf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwmf=		include/libwmf/libwmf/*.h
BUILDLINK_FILES.libwmf=		include/libwmf/libwmf/gd/*.h
BUILDLINK_FILES.libwmf+=	lib/libwmf-0.2.so*
BUILDLINK_FILES.libwmf+=	lib/libwmf.*

.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"

BUILDLINK_TARGETS.libwmf=	libwmf-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libwmf}

pre-configure: ${BUILDLINK_TARGETS.libwmf}
libwmf-buildlink: _BUILDLINK_USE

.endif	# LIBWMF_BUILDLINK_MK
