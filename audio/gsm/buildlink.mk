# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:19 jlam Exp $
#
# This Makefile fragment is included by packages that use gsm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gsm to the dependency pattern
#     for the version of gsm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GSM_BUILDLINK_MK)
GSM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gsm?=	gsm>=1.0.10
DEPENDS+=	${BUILDLINK_DEPENDS.gsm}:../../audio/gsm

EVAL_PREFIX+=		BUILDLINK_PREFIX.gsm=gsm
BUILDLINK_PREFIX.gsm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gsm=	include/gsm.h
BUILDLINK_FILES.gsm+=	include/gsm/*
BUILDLINK_FILES.gsm+=	lib/libgsm.*

BUILDLINK_TARGETS.gsm=	gsm-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gsm}

pre-configure: ${BUILDLINK_TARGETS.gsm}
gsm-buildlink: _BUILDLINK_USE

.endif	# GSM_BUILDLINK_MK
