# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 06:14:12 rh Exp $
#
# This Makefile fragment is included by packages that use GeometryKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GEOMETRYKIT_BUILDLINK2_MK)
GEOMETRYKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GeometryKit
BUILDLINK_DEPENDS.GeometryKit?=		GeometryKit>=0.3.1r2
BUILDLINK_PKGSRCDIR.GeometryKit?=		../../graphics/GeometryKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.GeometryKit=GeometryKit
BUILDLINK_PREFIX.GeometryKit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DBezier.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DBox.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DDefs.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DFunctions.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DIntersecting.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DLine.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrix.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrix3d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrix3f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrix4d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrix4f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DMatrixFunc.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DPlane.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DQuatFunc.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DQuaternion.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DSphere.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTrigonometry.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple2d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple2f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple3d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple3f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple4d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DTuple4f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector2d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector2f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector3d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector3f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector4d.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVector4f.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/G3DVectorFunc.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Headers/GeometryKit/GeometryKit.h
BUILDLINK_FILES.GeometryKit+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libGeometryKit.*

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	GeometryKit-buildlink

GeometryKit-buildlink: _BUILDLINK_USE

.endif	# GEOMETRYKIT_BUILDLINK2_MK
