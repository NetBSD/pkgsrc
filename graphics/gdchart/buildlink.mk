# $NetBSD: buildlink.mk,v 1.1 2002/07/24 08:22:03 agc Exp $
#
# This Makefile fragment is included by packages that use gdchart.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gdchart to the dependency pattern
#     for the version of gdchart desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GDCHART_BUILDLINK_MK)
GDCHART_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gdchart?=		gdchart>=0.10.1nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gdchart}:../../graphics/gdchart

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdchart=gdchart
BUILDLINK_PREFIX.gdchart_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gdchart+=	include/gdchart.h
BUILDLINK_FILES.gdchart+=	include/gdc.h
BUILDLINK_FILES.gdchart+=	include/gdcpie.h
BUILDLINK_FILES.gdchart+=	include/gifencode.h
BUILDLINK_FILES.gdchart+=	lib/libgdchart.*

.include "../../graphics/gd/buildlink.mk"

BUILDLINK_TARGETS.gdchart=	gdchart-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gdchart}

pre-configure: ${BUILDLINK_TARGETS}
gdchart-buildlink: _BUILDLINK_USE

.endif	# GDCHART_BUILDLINK_MK
