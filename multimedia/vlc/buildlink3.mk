# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:11:02 jlam Exp $
#
# This Makefile fragment is included by packages that use vlc.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VLC_BUILDLINK3_MK:=	${VLC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	vlc
.endif

.if !empty(VLC_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		vlc
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}vlc
BUILDLINK_API_DEPENDS.vlc?=		vlc>=0.7.1
BUILDLINK_ABI_DEPENDS.vlc?=	vlc>=0.7.2nb15
BUILDLINK_PKGSRCDIR.vlc?=	../../multimedia/vlc
.endif # VLC_BUILDLINK3_MK

.include "../../multimedia/libdvdcss/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../sysutils/vcdimager-devel/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
