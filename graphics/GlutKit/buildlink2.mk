# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 06:16:06 rh Exp $
#
# This Makefile fragment is included by packages that use GlutKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GLUTKIT_BUILDLINK2_MK)
GLUTKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GlutKit
BUILDLINK_DEPENDS.GlutKit?=		GlutKit>=0.3.1r2
BUILDLINK_PKGSRCDIR.GlutKit?=		../../graphics/GlutKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.GlutKit=GlutKit
BUILDLINK_PREFIX.GlutKit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GlutKit+=	share/GNUstep/Local/Headers/GlutKit/G3DGlutCamera.h
BUILDLINK_FILES.GlutKit+=	share/GNUstep/Local/Headers/GlutKit/G3DGlutKit.h
BUILDLINK_FILES.GlutKit+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libGlutKit.*

.include "../../graphics/RenderKit/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"

BUILDLINK_TARGETS+=	GlutKit-buildlink

GlutKit-buildlink: _BUILDLINK_USE

.endif	# GLUTKIT_BUILDLINK2_MK
