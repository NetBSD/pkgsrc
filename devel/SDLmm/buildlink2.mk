# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/07 13:52:21 salo Exp $
#
# This Makefile fragment is included by packages that use SDLmm.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(SDLMM_BUILDLINK2_MK)
SDLMM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			SDLmm
BUILDLINK_DEPENDS.SDLmm?=		SDLmm>=0.1.8
BUILDLINK_PKGSRCDIR.SDLmm?=		../../devel/SDLmm

EVAL_PREFIX+=	BUILDLINK_PREFIX.SDLmm=SDLmm
BUILDLINK_PREFIX.SDLmm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_audio.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_autoconfig.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_basesurface.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_cd.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_color.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_config.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_display.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_event.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_eventhandler.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_global.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_joystick.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_pixelformat.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_spoint.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_srect.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_surface.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_timer.h
BUILDLINK_FILES.SDLmm+=	include/SDLmm/sdlmm_videoinfo.h
BUILDLINK_FILES.SDLmm+=	lib/libSDLmm-0.1.*
BUILDLINK_FILES.SDLmm+=	lib/libSDLmm.*

.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	SDLmm-buildlink

SDLmm-buildlink: _BUILDLINK_USE

.endif	# SDLMM_BUILDLINK2_MK
