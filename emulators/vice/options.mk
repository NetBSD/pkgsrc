# $NetBSD: options.mk,v 1.1 2006/02/17 19:26:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=	esound ffmpeg lame gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
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
.include "../../x11/gnome-libs/buildlink3.mk"
.endif
