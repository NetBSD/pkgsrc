# $NetBSD: buildlink2.mk,v 1.1 2003/09/22 12:27:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use plib.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(PLIB_BUILDLINK2_MK)
PLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			plib
BUILDLINK_DEPENDS.plib?=		plib>=1.6.0
BUILDLINK_PKGSRCDIR.plib?=		../../games/plib

EVAL_PREFIX+=	BUILDLINK_PREFIX.plib=plib
BUILDLINK_PREFIX.plib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.plib+=	include/plib/*.h
BUILDLINK_FILES.plib+=	lib/libplib*
BUILDLINK_DEPMETHOD.plib=	build

.include "../../graphics/Mesa/buildlink2.mk"

BUILDLINK_TARGETS+=	plib-buildlink

plib-buildlink: _BUILDLINK_USE

.endif	# PLIB_BUILDLINK2_MK
