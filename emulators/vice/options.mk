# $NetBSD: options.mk,v 1.4 2007/05/29 08:41:29 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vice
# ffmpeg support for vice-1.21 needs at least ffmpeg-0.5.1
#PKG_SUPPORTED_OPTIONS=	esound ffmpeg lame gnome
PKG_SUPPORTED_OPTIONS=	esound lame gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-esd
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-ffmpeg
.include "../../multimedia/ffmpeg/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mlame)
.  include "../../audio/lame/buildlink3.mk"
.  endif
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomeui
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.endif
