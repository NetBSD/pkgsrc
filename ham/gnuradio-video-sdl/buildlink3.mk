# $NetBSD: buildlink3.mk,v 1.2 2020/08/30 21:11:08 tnn Exp $

BUILDLINK_TREE+=	gnuradio-video-sdl

.if !defined(GNURADIO_VIDEO_SDL_BUILDLINK3_MK)
GNURADIO_VIDEO_SDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-video-sdl?=	../../ham/gnuradio-video-sdl
.endif # GNURADIO_VIDEO_SDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-video-sdl
