# $NetBSD: buildlink.mk,v 1.4 2001/08/23 14:34:49 jlam Exp $
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

BUILDLINK_DEPENDS.libwmf?=	libwmf>=0.1.21
BUILD_DEPENDS+=	${BUILDLINK_DEPENDS.libwmf}:../../graphics/libwmf

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwmf=libwmf
BUILDLINK_PREFIX.libwmf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwmf=		include/libwmf/*.h
BUILDLINK_FILES.libwmf+=	lib/libXwmf.a
BUILDLINK_FILES.libwmf+=	lib/libdib.a
BUILDLINK_FILES.libwmf+=	lib/libeps.a
BUILDLINK_FILES.libwmf+=	lib/libepswmf.a
BUILDLINK_FILES.libwmf+=	lib/libgdwmf.a
BUILDLINK_FILES.libwmf+=	lib/libwmf.a
BUILDLINK_FILES.libwmf+=	lib/libxfig.a
BUILDLINK_FILES.libwmf+=	lib/libxfwmf.a
BUILDLINK_FILES.libwmf+=	lib/libxgd.a

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"

BUILDLINK_TARGETS.libwmf=	libwmf-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.libwmf}

pre-configure: ${BUILDLINK_TARGETS.libwmf}
libwmf-buildlink: _BUILDLINK_USE

.endif	# LIBWMF_BUILDLINK_MK
