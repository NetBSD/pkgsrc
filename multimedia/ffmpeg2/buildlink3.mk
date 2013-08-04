# $NetBSD: buildlink3.mk,v 1.1 2013/08/04 10:29:02 adam Exp $

BUILDLINK_TREE+=	ffmpeg2

.if !defined(FFMPEG2_BUILDLINK3_MK)
FFMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg2+=	ffmpeg2>=2.0
BUILDLINK_ABI_DEPENDS.ffmpeg2+=	ffmpeg2>=2.0
BUILDLINK_PKGSRCDIR.ffmpeg2?=	../../multimedia/ffmpeg2

pkgbase := ffmpeg2
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

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

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg2
