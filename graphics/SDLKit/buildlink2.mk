# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/29 06:16:53 rh Exp $
#
# This Makefile fragment is included by packages that use SDLKit.
#
# This file was created automatically using createbuildlink 2.1.
#

.if !defined(SDLKIT_BUILDLINK2_MK)
SDLKIT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			SDLKit
BUILDLINK_DEPENDS.SDLKit?=		SDLKit>=0.3.1r2
BUILDLINK_PKGSRCDIR.SDLKit?=		../../graphics/SDLKit

EVAL_PREFIX+=	BUILDLINK_PREFIX.SDLKit=SDLKit
BUILDLINK_PREFIX.SDLKit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDLKit+=	share/GNUstep/Local/Headers/SDLKit/G3DSDLCamera.h
BUILDLINK_FILES.SDLKit+=	share/GNUstep/Local/Headers/SDLKit/G3DSDLEventHandler.h
BUILDLINK_FILES.SDLKit+=	share/GNUstep/Local/Headers/SDLKit/G3DSDLKit.h
BUILDLINK_FILES.SDLKit+=	share/GNUstep/Local/Libraries/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu/libSDLKit.*

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/RenderKit/buildlink2.mk"

BUILDLINK_TARGETS+=	SDLKit-buildlink

SDLKit-buildlink: _BUILDLINK_USE

.endif	# SDLKIT_BUILDLINK2_MK
