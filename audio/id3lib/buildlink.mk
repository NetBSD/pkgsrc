# $NetBSD: buildlink.mk,v 1.2 2002/04/18 14:34:18 wiz Exp $
#
# This Makefile fragment is included by packages that use id3lib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.id3lib to the dependency pattern
#     for the version of id3lib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ID3LIB_BUILDLINK_MK)
ID3LIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.id3lib?=	id3lib>=3.8.0
DEPENDS+=	${BUILDLINK_DEPENDS.id3lib}:../../audio/id3lib

EVAL_PREFIX+=		BUILDLINK_PREFIX.id3lib=id3lib
BUILDLINK_PREFIX.id3lib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.id3lib=		include/id3.h
BUILDLINK_FILES.id3lib+=	include/id3/*
BUILDLINK_FILES.id3lib+=	lib/libid3*.*

BUILDLINK_TARGETS.id3lib=	id3lib-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.id3lib}

pre-configure: ${BUILDLINK_TARGETS.id3lib}
id3lib-buildlink: _BUILDLINK_USE

.endif	# ID3LIB_BUILDLINK_MK
