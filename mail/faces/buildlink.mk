# $NetBSD: buildlink.mk,v 1.4 2001/11/30 16:29:28 jlam Exp $
#
# This Makefile fragment is included by packages that use faces.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.faces to the dependency pattern
#     for the version of faces desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FACES_BUILDLINK_MK)
FACES_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.faces?=	faces>=1.6.1nb1
DEPENDS+=	${BUILDLINK_DEPENDS.faces}:../../mail/faces

EVAL_PREFIX+=			BUILDLINK_PREFIX.faces=faces
BUILDLINK_PREFIX.faces_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.faces=		include/compface.h
BUILDLINK_FILES.faces+=		lib/libcompface.*

BUILDLINK_TARGETS.faces=	faces-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.faces}

pre-configure: ${BUILDLINK_TARGETS.faces}
faces-buildlink: _BUILDLINK_USE

.endif	# FACES_BUILDLINK_MK
