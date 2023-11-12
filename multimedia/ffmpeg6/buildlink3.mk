# $NetBSD: buildlink3.mk,v 1.2 2023/11/12 13:22:56 wiz Exp $

BUILDLINK_TREE+=	ffmpeg6

.if !defined(FFMPEG6_BUILDLINK3_MK)
FFMPEG6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg6+=	ffmpeg6>=6.0
BUILDLINK_ABI_DEPENDS.ffmpeg6?=	ffmpeg6>=6.0nb6
BUILDLINK_PKGSRCDIR.ffmpeg6?=	../../multimedia/ffmpeg6

pkgbase := ffmpeg6
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mav1}
.  include "../../multimedia/libaom/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mx264}
.  include "../../multimedia/x264/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg6:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg6+=		include/ffmpeg6
BUILDLINK_LIBDIRS.ffmpeg6+=		lib/ffmpeg6
BUILDLINK_FNAME_TRANSFORM.ffmpeg6+=	-e 's|lib/ffmpeg6/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG6_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg6
