# $NetBSD: options.mk,v 1.1 2006/06/12 16:20:44 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL
PKG_SUPPORTED_OPTIONS=	arts esound nas
PKG_SUGGESTED_OPTIONS=	arts esound nas

.include "../../mk/bsd.options.mk"

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
