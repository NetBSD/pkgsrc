# $NetBSD: buildlink3.mk,v 1.5 2008/05/06 15:43:03 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FFMPEG_DEVEL_BUILDLINK3_MK:=	${FFMPEG_DEVEL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ffmpeg-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nffmpeg-devel}
BUILDLINK_PACKAGES+=	ffmpeg-devel
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ffmpeg-devel

.if ${FFMPEG_DEVEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ffmpeg-devel+=	ffmpeg-devel>=20071004
BUILDLINK_PKGSRCDIR.ffmpeg-devel?=	../../multimedia/ffmpeg-devel

pkgbase := ffmpeg-devel
.  include "../../mk/pkg-build-options.mk"

.endif	# FFMPEG_DEVEL_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Msdl)
.  include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mtheora)
.  include "../../multimedia/libtheora/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mxvid)
.  include "../../multimedia/xvidcore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mlame)
.  include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mvorbis)
.  include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ffmpeg-devel:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.endif

.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
