# $NetBSD: buildlink2.mk,v 1.3 2003/05/24 08:08:57 salo Exp $
#
# This Makefile fragment is included by packages that use lib3ds.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIB3DS_BUILDLINK2_MK)
LIB3DS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			lib3ds
BUILDLINK_DEPENDS.lib3ds?=		lib3ds>=1.2.0
BUILDLINK_PKGSRCDIR.lib3ds?=		../../graphics/lib3ds

EVAL_PREFIX+=	BUILDLINK_PREFIX.lib3ds=lib3ds
BUILDLINK_PREFIX.lib3ds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lib3ds+=	include/lib3ds/*
BUILDLINK_FILES.lib3ds+=	lib/lib3ds.*

.include "../../graphics/Mesa/buildlink2.mk"

BUILDLINK_TARGETS+=	lib3ds-buildlink

lib3ds-buildlink: _BUILDLINK_USE

.endif	# LIB3DS_BUILDLINK2_MK
