# $NetBSD: options.mk,v 1.4 2017/09/08 12:45:33 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-lwt
PKG_SUPPORTED_OPTIONS=	camlp4
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=	camlp4

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### Camlp4 support
###
.if !empty(PKG_OPTIONS:Mcamlp4)
.include "../../lang/camlp4/buildlink3.mk"
CONFIGURE_ARGS+=	-use-camlp4 true
PLIST.camlp4=	yes
.else
CONFIGURE_ARGS+=	-use-camlp4 false
.endif
