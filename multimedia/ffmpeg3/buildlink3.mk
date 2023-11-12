# $NetBSD: buildlink3.mk,v 1.15 2023/11/12 13:22:55 wiz Exp $

BUILDLINK_TREE+=	ffmpeg3

.if !defined(FFMPEG3_BUILDLINK3_MK)
FFMPEG3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffmpeg3+=	ffmpeg3>=3.0
BUILDLINK_ABI_DEPENDS.ffmpeg3+=	ffmpeg3>=3.4.11nb15
BUILDLINK_PKGSRCDIR.ffmpeg3?=	../../multimedia/ffmpeg3

pkgbase := ffmpeg3
.include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mfreetype}
.  include "../../graphics/freetype2/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mfontconfig}
.  include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mtheora}
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mxvid}
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mx264}
.  include "../../multimedia/x264/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mlibvpx}
.  include "../../multimedia/libvpx/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mvaapi}
.  include "../../multimedia/libva/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.ffmpeg3:Mvdpau}
.  include "../../multimedia/libvdpau/buildlink3.mk"
.endif

BUILDLINK_INCDIRS.ffmpeg3+=		include/ffmpeg3
BUILDLINK_LIBDIRS.ffmpeg3+=		lib/ffmpeg3
BUILDLINK_FNAME_TRANSFORM.ffmpeg3+=	-e 's|lib/ffmpeg3/pkgconfig/|lib/pkgconfig/|'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # FFMPEG3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffmpeg3
