# $NetBSD: buildlink3.mk,v 1.15 2022/06/28 11:34:54 wiz Exp $

BUILDLINK_TREE+=	ffmpeg2

.if !defined(FFMPEG2_BUILDLINK3_MK)
FFMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg2+=	ffmpeg2>=2.0
BUILDLINK_ABI_DEPENDS.ffmpeg2+=	ffmpeg2>=2.8.20nb1
BUILDLINK_PKGSRCDIR.ffmpeg2?=	../../multimedia/ffmpeg2

pkgbase := ffmpeg2
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mfreetype)
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mfontconfig)
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mtheora)
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mxvid)
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg2:Mlibvpx)
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg2+=		include/ffmpeg2
BUILDLINK_LIBDIRS.ffmpeg2+=		lib/ffmpeg2
BUILDLINK_FNAME_TRANSFORM.ffmpeg2+=	-e 's|lib/ffmpeg2/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg2
