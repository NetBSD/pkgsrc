# $NetBSD: kpathsea.buildlink.mk,v 1.1.2.2 2002/06/23 18:58:31 jlam Exp $
#
# This Makefile fragment is included by packages that use libkpathsea.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kpathsea to the dependency pattern
#     for the version of libkpathsea desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KPATHSEA_BUILDLINK_MK)
KPATHSEA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kpathsea?=	teTeX-bin>=1.0.7nb2
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.kpathsea}:../../print/teTeX-bin

EVAL_PREFIX+=		BUILDLINK_PREFIX.kpathsea=teTeX-bin
BUILDLINK_PREFIX.kpathsea_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kpathsea=	include/kpathsea/*
BUILDLINK_FILES.kpathsea+=	lib/libkpathsea.a

BUILDLINK_TARGETS.kpathsea=	kpathsea-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.kpathsea}

pre-configure: ${BUILDLINK_TARGETS}
kpathsea-buildlink: _BUILDLINK_USE

.endif	# KPATHSEA_BUILDLINK_MK
