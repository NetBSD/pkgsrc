# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 06:15:34 rh Exp $
#
# This Makefile fragment is included by packages that use GLXKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(GLXKIT_BUILDLINK2_MK)
GLXKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GLXKit
BUILDLINK_DEPENDS.GLXKit?=		GLXKit>=0.3.1r2
BUILDLINK_PKGSRCDIR.GLXKit?=		../../graphics/GLXKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.GLXKit=GLXKit
BUILDLINK_PREFIX.GLXKit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GLXKit+=	share/GNUstep/Local/Headers/GLXKit/G3DGLXCamera.h
BUILDLINK_FILES.GLXKit+=	share/GNUstep/Local/Headers/GLXKit/G3DGLXKit.h
BUILDLINK_FILES.GLXKit+=	share/GNUstep/Local/Headers/GLXKit/G3DXEventHandler.h
BUILDLINK_FILES.GLXKit+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libGLXKit.*

.include "../../graphics/RenderKit/buildlink2.mk"

BUILDLINK_TARGETS+=	GLXKit-buildlink

GLXKit-buildlink: _BUILDLINK_USE

.endif	# GLXKIT_BUILDLINK2_MK
