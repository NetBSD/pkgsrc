# $NetBSD: options.mk,v 1.3 2013/01/31 22:01:43 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gawk
PKG_SUPPORTED_OPTIONS=	portals readline
PKG_SUGGESTED_OPTIONS=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportals)
CONFIGURE_ARGS+=	--enable-portals
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif
