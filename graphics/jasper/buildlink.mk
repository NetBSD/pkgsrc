# $NetBSD: buildlink.mk,v 1.1.1.1 2001/08/01 14:56:31 rh Exp $
#
# This Makefile fragment is included by packages that use libjasper.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.jasper to the dependency pattern
#     for the version of libjasper desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JASPER_BUILDLINK_MK)
JASPER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.jasper?=	jasper-1.500.0
DEPENDS+=	${BUILDLINK_DEPENDS.jasper}:../../graphics/jasper

EVAL_PREFIX+=		BUILDLINK_PREFIX.jasper=jasper
BUILDLINK_PREFIX.jasper_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jasper=	include/jasper/jas_debug.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_fix.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_getopt.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_image.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_init.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_malloc.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_math.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_seq.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_stream.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_string.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_tvp.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_types.h
BUILDLINK_FILES.jasper+=	include/jasper/jas_version.h
BUILDLINK_FILES.jasper+=	include/jasper/jasper.h
BUILDLINK_FILES.jasper+=	lib/libjasper.*

BUILDLINK_TARGETS.jasper=	jasper-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.jasper}

pre-configure: ${BUILDLINK_TARGETS.jasper}
jasper-buildlink: _BUILDLINK_USE

.endif	# JASPER_BUILDLINK_MK
