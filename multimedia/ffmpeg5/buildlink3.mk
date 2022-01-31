# $NetBSD: buildlink3.mk,v 1.1 2022/01/31 23:16:41 ryoon Exp $

BUILDLINK_TREE+=	ffmpeg5

.if !defined(FFMPEG5_BUILDLINK3_MK)
FFMPEG5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg5+=	ffmpeg5>=5.0
BUILDLINK_ABI_DEPENDS.ffmpeg5+=	ffmpeg5>=5.0
BUILDLINK_PKGSRCDIR.ffmpeg5?=	../../multimedia/ffmpeg5

pkgbase := ffmpeg5
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mav1}
.  include "../../multimedia/libaom/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mx264}
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg5:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg5+=		include/ffmpeg5
BUILDLINK_LIBDIRS.ffmpeg5+=		lib/ffmpeg5
BUILDLINK_FNAME_TRANSFORM.ffmpeg5+=	-e 's|lib/ffmpeg5/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG5_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg5
