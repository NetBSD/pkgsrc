# $NetBSD: options.mk,v 1.1 2012/05/30 13:40:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-lwt
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/ocaml-ssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
