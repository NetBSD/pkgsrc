# $NetBSD: buildlink.mk,v 1.1 2001/08/19 19:09:40 jlam Exp $
#
# This Makefile fragment is included by packages that use xlHtml.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.xlHtml to the dependency pattern
#     for the version of xlHtml desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(XLHTML_BUILDLINK_MK)
XLHTML_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.xlHtml?=	xlHtml>=0.2.8
DEPENDS+=	${BUILDLINK_DEPENDS.xlHtml}:../../databases/xlHtml

EVAL_PREFIX+=			BUILDLINK_PREFIX.xlHtml=xlHtml
BUILDLINK_PREFIX.xlHtml_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xlHtml=		include/cole/*
BUILDLINK_FILES.xlHtml+=	lib/libcole.*

BUILDLINK_TARGETS.xlHtml=	xlHtml-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.xlHtml}

pre-configure: ${BUILDLINK_TARGETS.xlHtml}
xlHtml-buildlink: _BUILDLINK_USE

.endif	# XLHTML_BUILDLINK_MK
