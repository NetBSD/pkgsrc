# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/06 00:52:29 rh Exp $
#
# This Makefile fragment is included by packages that use lib3ds.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(LIB3DS_BUILDLINK2_MK)
LIB3DS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			lib3ds
BUILDLINK_DEPENDS.lib3ds?=		lib3ds>=1.2.0
BUILDLINK_PKGSRCDIR.lib3ds?=		../../graphics/lib3ds

EVAL_PREFIX+=	BUILDLINK_PREFIX.lib3ds=lib3ds
BUILDLINK_PREFIX.lib3ds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lib3ds+=	include/lib3ds/atmosphere.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/background.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/camera.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/chunk.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/ease.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/file.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/float.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/io.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/light.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/material.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/matrix.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/mesh.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/node.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/quat.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/shadow.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/tcb.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/tracks.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/types.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/vector.h
BUILDLINK_FILES.lib3ds+=	include/lib3ds/viewport.h
BUILDLINK_FILES.lib3ds+=	lib/lib3ds.*

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

BUILDLINK_TARGETS+=	lib3ds-buildlink

lib3ds-buildlink: _BUILDLINK_USE

.endif	# LIB3DS_BUILDLINK2_MK
