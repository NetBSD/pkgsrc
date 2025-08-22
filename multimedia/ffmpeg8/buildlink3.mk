# $NetBSD: buildlink3.mk,v 1.1 2025/08/22 16:42:06 wiz Exp $

BUILDLINK_TREE+=	ffmpeg8

.if !defined(FFMPEG8_BUILDLINK3_MK)
FFMPEG8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg8+=	ffmpeg8>=8.0
BUILDLINK_PKGSRCDIR.ffmpeg8?=	../../multimedia/ffmpeg8

pkgbase := ffmpeg8
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mav1}
.  include "../../multimedia/libaom/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mx264}
.  include "../../multimedia/x264/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg8:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg8+=		include/ffmpeg8
BUILDLINK_LIBDIRS.ffmpeg8+=		lib/ffmpeg8
BUILDLINK_FNAME_TRANSFORM.ffmpeg8+=	-e 's|lib/ffmpeg8/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG8_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg8
