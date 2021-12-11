# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:57:51 tnn Exp $

BUILDLINK_TREE+=	gnuradio-video-sdl

.if !defined(GNURADIO_VIDEO_SDL_BUILDLINK3_MK)
GNURADIO_VIDEO_SDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-video-sdl?=	../../ham/gnuradio-video-sdl
.endif # GNURADIO_VIDEO_SDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-video-sdl
