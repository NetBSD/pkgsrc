# $NetBSD: options.mk,v 1.2 2017/09/08 13:19:34 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.js_of_ocaml
PKG_SUPPORTED_OPTIONS=	ocaml-tyxml camlp4
PKG_SUGGESTED_OPTIONS=	ocaml-tyxml

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	tyxml camlp4

###
### TyXML support
###
.if !empty(PKG_OPTIONS:Mocaml-tyxml)
.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../devel/ocaml-reactiveData/buildlink3.mk"
PLIST.tyxml=	yes
JBUILDER_BUILD_PACKAGES+=	js_of_ocaml-tyxml
OPAM_INSTALL_FILES+=	js_of_ocaml-tyxml
.else
.endif

###
### Camlp4 support
###
.if !empty(PKG_OPTIONS:Mcamlp4)
.include "../../lang/camlp4/buildlink3.mk"
PLIST.camlp4=	yes
JBUILDER_BUILD_PACKAGES+=	js_of_ocaml-camlp4
OPAM_INSTALL_FILES+=	js_of_ocaml-camlp4
.else
.endif
