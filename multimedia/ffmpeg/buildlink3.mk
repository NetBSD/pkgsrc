# $NetBSD: buildlink3.mk,v 1.11 2008/12/18 17:28:16 bjs Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FFMPEG_BUILDLINK3_MK:=	${FFMPEG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ffmpeg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nffmpeg}
BUILDLINK_PACKAGES+=	ffmpeg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ffmpeg

.if ${FFMPEG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ffmpeg+=	ffmpeg>=20080727
BUILDLINK_ABI_DEPENDS.ffmpeg?=	ffmpeg>=20080727nb6
BUILDLINK_PKGSRCDIR.ffmpeg?=	../../multimedia/ffmpeg

pkgbase := ffmpeg
.  include "../../mk/pkg-build-options.mk"

.endif	# FFMPEG_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.ffmpeg:Msdl)
.  include "../../devel/SDL/buildlink3.mk"
.endif

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

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
