# $NetBSD: buildlink2.mk,v 1.2 2003/12/03 21:18:10 xtraeme Exp $
#
# This Makefile fragment is included by packages that use ogre.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(OGRE_BUILDLINK2_MK)
OGRE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ogre
BUILDLINK_DEPENDS.ogre?=		ogre>=0.12.0
BUILDLINK_PKGSRCDIR.ogre?=		../../devel/ogre

EVAL_PREFIX+=	BUILDLINK_PREFIX.ogre=ogre
BUILDLINK_PREFIX.ogre_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ogre+=	include/OGRE/*.h
BUILDLINK_FILES.ogre+=	lib/OGRE/*
BUILDLINK_FILES.ogre+=	lib/libOgreMain.*
BUILDLINK_FILES.ogre+=	lib/libOgrePlatform.*
BUILDLINK_FILES.ogre+=	lib/pkgconfig/OGRE.pc

.include "../../devel/devIL/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

BUILDLINK_TARGETS+=	ogre-buildlink

ogre-buildlink: _BUILDLINK_USE

.endif	# OGRE_BUILDLINK2_MK
