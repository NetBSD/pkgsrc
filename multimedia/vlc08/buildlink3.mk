# $NetBSD: buildlink3.mk,v 1.22 2012/09/22 13:48:19 ryoon Exp $

BUILDLINK_TREE+=	vlc08

.if !defined(VLC08_BUILDLINK3_MK)
VLC08_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vlc08+=	vlc08>=0.8.6d
BUILDLINK_ABI_DEPENDS.vlc08+=	vlc08>=0.8.6inb25
BUILDLINK_PKGSRCDIR.vlc08?=	../../multimedia/vlc08

pkgbase:= vlc08
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.vlc:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif # VLC08_BUILDLINK3_MK

BUILDLINK_TREE+=	-vlc08
