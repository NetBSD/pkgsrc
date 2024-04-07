# $NetBSD: buildlink3.mk,v 1.1 2024/04/07 17:50:23 ryoon Exp $

BUILDLINK_TREE+=	ffmpeg7

.if !defined(FFMPEG7_BUILDLINK3_MK)
FFMPEG7_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg7+=	ffmpeg7>=7.0
BUILDLINK_PKGSRCDIR.ffmpeg7?=	../../multimedia/ffmpeg7

pkgbase := ffmpeg7
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mav1}
.  include "../../multimedia/libaom/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mx264}
.  include "../../multimedia/x264/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg7:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg7+=		include/ffmpeg7
BUILDLINK_LIBDIRS.ffmpeg7+=		lib/ffmpeg7
BUILDLINK_FNAME_TRANSFORM.ffmpeg7+=	-e 's|lib/ffmpeg7/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG7_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg7
