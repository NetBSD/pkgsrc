# $NetBSD: options.mk,v 1.2 2006/06/15 09:45:05 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL
PKG_SUPPORTED_OPTIONS=	aalib arts esound nas
PKG_SUGGESTED_OPTIONS=	aalib arts esound nas

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
CONFIGURE_ARGS+=	--enable-video-aalib
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
.include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esd
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--enable-nas
.include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif
