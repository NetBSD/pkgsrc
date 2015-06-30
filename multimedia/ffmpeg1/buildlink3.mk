# $NetBSD: buildlink3.mk,v 1.2 2015/06/30 10:02:22 ryoon Exp $

BUILDLINK_TREE+=	ffmpeg1

.if !defined(FFMPEG1_BUILDLINK3_MK)
FFMPEG1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg1+=	ffmpeg1>=1.2.6nb1
BUILDLINK_ABI_DEPENDS.ffmpeg1?=	ffmpeg1>=1.2.12nb1
BUILDLINK_PKGSRCDIR.ffmpeg1?=	../../multimedia/ffmpeg1

pkgbase := ffmpeg1
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg1:Mtheora)
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg1:Mxvid)
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg1:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg1:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg1:Mlibvpx)
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg1+=		include/ffmpeg1
BUILDLINK_LIBDIRS.ffmpeg1+=		lib/ffmpeg1
BUILDLINK_FNAME_TRANSFORM.ffmpeg1+=	-e 's|lib/ffmpeg1/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG1_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg1
