# $NetBSD: buildlink.mk,v 1.1 2001/06/29 22:48:24 zuntum Exp $
#
# This Makefile fragment is included by packages that use gd.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gd to the dependency pattern
#     for the version of gd desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GD_BUILDLINK_MK)
GD_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.gd?=	gd>=1.8.3
DEPENDS+=	${BUILDLINK_DEPENDS.gd}:../../graphics/gd

BUILDLINK_PREFIX.gd=	${LOCALBASE}
BUILDLINK_FILES.gd=	include/gd*.h
BUILDLINK_FILES.gd+=	lib/libgd.*

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"

BUILDLINK_TARGETS.gd=	gd-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gd}

pre-configure: ${BUILDLINK_TARGETS.gd}
gd-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# GD_BUILDLINK_MK
