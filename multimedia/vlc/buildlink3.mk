# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/29 10:30:29 grant Exp $
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
BUILDLINK_DEPENDS.vlc?=		vlc>=0.7.1
BUILDLINK_PKGSRCDIR.vlc?=	../../wip/videolanclient

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libmpeg2/buildlink3.mk"
.include "../../misc/libdvdcss/buildlink3.mk"
.include "../../misc/libdvdplay/buildlink3.mk"
.include "../../misc/libdvdread/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.endif # VLC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
