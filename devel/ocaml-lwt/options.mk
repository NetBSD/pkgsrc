# $NetBSD: options.mk,v 1.3 2017/07/11 11:06:54 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-lwt
PKG_SUPPORTED_OPTIONS=	ssl ppx camlp4
PKG_SUGGESTED_OPTIONS=	ssl ppx camlp4
PLIST_VARS+=	ppx camlp4

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/ocaml-ssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.ocaml-ssl+=	ocaml-ssl>=0.5.0
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### Camlp4 support
###
.if !empty(PKG_OPTIONS:Mcamlp4)
.include "../../lang/camlp4/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-camlp4
PLIST.camlp4=	yes
.else
CONFIGURE_ARGS+=	--disable-camlp4
.endif

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mppx)
CONFIGURE_ARGS+=	--enable-ppx
PLIST.ppx=	yes
.else
CONFIGURE_ARGS+=	--disable-ppx
.endif
