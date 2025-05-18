# $NetBSD: buildlink3.mk,v 1.7 2025/05/18 19:31:21 gdt Exp $

BUILDLINK_TREE+=	gnuradio-video-sdl

.if !defined(GNURADIO_VIDEO_SDL_BUILDLINK3_MK)
GNURADIO_VIDEO_SDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-video-sdl?=	gnuradio-video-sdl>=3.10.12.0nb3
BUILDLINK_PKGSRCDIR.gnuradio-video-sdl?=	../../ham/gnuradio-video-sdl

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_VIDEO_SDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-video-sdl
