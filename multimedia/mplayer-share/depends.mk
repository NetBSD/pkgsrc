# $NetBSD: depends.mk,v 1.1 2022/04/24 15:00:42 nia Exp $
#

DEPENDS+=	mplayer-share>=${MPLAYER_VERSION}:../../multimedia/mplayer-share

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
