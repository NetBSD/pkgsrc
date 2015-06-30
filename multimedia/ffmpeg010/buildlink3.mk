# $NetBSD: buildlink3.mk,v 1.8 2015/06/30 10:02:22 ryoon Exp $

BUILDLINK_TREE+=	ffmpeg010

.if !defined(FFMPEG010_BUILDLINK3_MK)
FFMPEG010_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg010+=	ffmpeg010>=20120609.0.10.4
BUILDLINK_ABI_DEPENDS.ffmpeg010?=	ffmpeg010>=20150312.0.10.16nb1
BUILDLINK_PKGSRCDIR.ffmpeg010?=	../../multimedia/ffmpeg010

BUILDLINK_INCDIRS.ffmpeg010+=		include/ffmpeg010
BUILDLINK_LIBDIRS.ffmpeg010+=		lib/ffmpeg010
BUILDLINK_FNAME_TRANSFORM.ffmpeg010+=   -e 's|lib/ffmpeg010/pkgconfig/|lib/pkgconfig/|'

pkgbase := ffmpeg010
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg010:Mtheora)
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg010:Mxvid)
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg010:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg010:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg010:Mlibvpx)
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG010_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg010
