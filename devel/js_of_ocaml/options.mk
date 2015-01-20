# $NetBSD: options.mk,v 1.1 2015/01/20 16:09:15 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.js_of_ocaml
PKG_SUPPORTED_OPTIONS=	ocaml-tyxml
PKG_SUGGESTED_OPTIONS=	ocaml-tyxml

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	tyxml
###
### TyXML support
###
.if !empty(PKG_OPTIONS:Mocaml-tyxml)
.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../devel/ocaml-reactiveData/buildlink3.mk"
MAKE_ENV+=	USE_TYXML="YES" USE_REACT="YES"
PLIST.tyxml=	yes
.else
MAKE_ENV+=	USE_TYXML="NO" USE_REACT="NO"
.endif
