# $NetBSD: buildlink.mk,v 1.1 2001/08/06 13:57:48 wiz Exp $
#
# This Makefile fragment is included by packages that use psiconv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.psiconv to the dependency pattern
#     for the version of psiconv desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PSICONV_BUILDLINK_MK)
PSICONV_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.psiconv?=	psiconv>=0.6.1
DEPENDS+=		${BUILDLINK_DEPENDS.psiconv}:../../converters/psiconv

EVAL_PREFIX+=				BUILDLINK_PREFIX.psiconv=psiconv
BUILDLINK_PREFIX.psiconv_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.psiconv=	include/psiconv/data.h
BUILDLINK_FILES.psiconv+=	include/psiconv/list.h
BUILDLINK_FILES.psiconv+=	include/psiconv/parse.h
BUILDLINK_FILES.psiconv+=	include/psiconv/parse_routines.h
BUILDLINK_FILES.psiconv+=	lib/libpsiconv.*

BUILDLINK_TARGETS.psiconv=	psiconv-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.psiconv}

pre-configure: ${BUILDLINK_TARGETS.psiconv}
psiconv-buildlink: _BUILDLINK_USE

.endif	# PSICONV_BUILDLINK_MK
