# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 19:00:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use DevIL.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(DEVIL_BUILDLINK2_MK)
DEVIL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			DevIL
BUILDLINK_DEPENDS.DevIL?=		DevIL>=1.6.6
BUILDLINK_PKGSRCDIR.DevIL?=		../../devel/devIL

EVAL_PREFIX+=	BUILDLINK_PREFIX.DevIL=DevIL
BUILDLINK_PREFIX.DevIL_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.DevIL+=	include/IL/*.h
BUILDLINK_FILES.DevIL+=	lib/libIL.*
BUILDLINK_FILES.DevIL+=	lib/libILU.*
BUILDLINK_FILES.DevIL+=	lib/libILUT.*

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	DevIL-buildlink

DevIL-buildlink: _BUILDLINK_USE

.endif	# DEVIL_BUILDLINK2_MK
