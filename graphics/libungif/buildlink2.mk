# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:41 jlam Exp $
#
# This Makefile fragment is included by packages that use libungif.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libungif to the dependency pattern
#     for the version of libungif desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBUNGIF_BUILDLINK2_MK)
LIBUNGIF_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.libungif?=	libungif>=4.1.0
DEPENDS+=	${BUILDLINK_DEPENDS.libungif}:../../graphics/libungif

EVAL_PREIFX+=	BUILDLINK_PREFIX.libungif=libungif
BUILDLINK_PREFIX.libungif_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libungif=	include/gif_lib.h
BUILDLINK_FILES.libungif+=	lib/libgif.*
BUILDLINK_FILES.libungif+=	lib/libungif.*

BUILDLINK_TARGETS+=		libungif-buildlink

libungif-buildlink: _BUILDLINK_USE

.endif	# LIBUNGIF_BUILDLINK2_MK
