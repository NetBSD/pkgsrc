# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 06:14:50 rh Exp $
#
# This Makefile fragment is included by packages that use RenderKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(RENDERKIT_BUILDLINK2_MK)
RENDERKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			RenderKit
BUILDLINK_DEPENDS.RenderKit?=		RenderKit>=0.3.1r2
BUILDLINK_PKGSRCDIR.RenderKit?=		../../graphics/RenderKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.RenderKit=RenderKit
BUILDLINK_PREFIX.RenderKit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DArchiver.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DArchivingInfo.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DAttributeNode.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DBVol.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DBillboard.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DCamera.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DColour.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DDefines.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DFileHandler.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DFog.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DFrustum.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DFunctions.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DGeometryBackend.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DGeometryExtensions.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DGraphNode.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DGroup.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DIVtxArray.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DLODGroup.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DLeaf.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DLight.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DMaterial.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DNodeEnumerator.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DNodeList.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DOverlay.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DRenderEngine.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DRotator.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DSceneCoding.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DShape+Surface.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DShape.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DState.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DSurface.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DSwitchGroup.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DTexture.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DTimedSwitchGroup.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DTransform.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DTypes.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DUnarchiver.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DVtxArray.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/G3DWorld.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/NSObject+G3DExtensions.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Headers/RenderKit/RenderKit.h
BUILDLINK_FILES.RenderKit+=	share/GNUstep/System/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libRenderKit.*

.include "../../graphics/GeometryKit/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"

BUILDLINK_TARGETS+=	RenderKit-buildlink

RenderKit-buildlink: _BUILDLINK_USE

.endif	# RENDERKIT_BUILDLINK2_MK
