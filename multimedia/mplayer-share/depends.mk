# $NetBSD: depends.mk,v 1.2 2025/11/15 12:43:17 ryoon Exp $
#

DEPENDS+=	mplayer-share>=${MPLAYER_VERSION}:../../multimedia/mplayer-share

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
