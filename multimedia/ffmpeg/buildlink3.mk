# $NetBSD: buildlink3.mk,v 1.13 2009/06/12 16:39:49 ahoka Exp $

BUILDLINK_TREE+=	ffmpeg

.if !defined(FFMPEG_BUILDLINK3_MK)
FFMPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg+=	ffmpeg>=20090611
BUILDLINK_ABI_DEPENDS.ffmpeg?=	ffmpeg>=20090611
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

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.include "../../devel/libgetopt/buildlink3.mk"
.endif # FFMPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg
