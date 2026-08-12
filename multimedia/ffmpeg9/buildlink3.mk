# $NetBSD: buildlink3.mk,v 1.1 2026/08/12 03:43:35 ryoon Exp $

BUILDLINK_TREE+=	ffmpeg9

.if !defined(FFMPEG9_BUILDLINK3_MK)
FFMPEG9_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg9+=	ffmpeg9>=9.0
BUILDLINK_ABI_DEPENDS.ffmpeg9?=	ffmpeg9>=9.0
BUILDLINK_PKGSRCDIR.ffmpeg9?=	../../multimedia/ffmpeg9

pkgbase := ffmpeg9
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mav1}
.  include "../../multimedia/libaom/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mx264}
.  include "../../multimedia/x264/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg9:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg9+=		include/ffmpeg9
BUILDLINK_LIBDIRS.ffmpeg9+=		lib/ffmpeg9
BUILDLINK_FNAME_TRANSFORM.ffmpeg9+=	-e 's|lib/ffmpeg9/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG9_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg9
