# $NetBSD: buildlink3.mk,v 1.24 2014/04/10 05:39:14 obache Exp $

BUILDLINK_TREE+=	ffmpeg

.if !defined(FFMPEG_BUILDLINK3_MK)
FFMPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg+=	ffmpeg>=20120919.0.10.5
BUILDLINK_ABI_DEPENDS.ffmpeg+=	ffmpeg>=20140305.1.2.6nb1
BUILDLINK_PKGSRCDIR.ffmpeg?=	../../multimedia/ffmpeg

pkgbase := ffmpeg
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mtheora)
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mxvid)
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mlibvpx)
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg
