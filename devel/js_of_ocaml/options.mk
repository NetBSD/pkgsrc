# $NetBSD: options.mk,v 1.6 2018/11/29 11:59:21 jaapb Exp $

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
DUNE_BUILD_PACKAGES+=	js_of_ocaml-tyxml
OPAM_INSTALL_FILES+=	js_of_ocaml-tyxml
.else
.endif

###
### Camlp4 support
###
.if !empty(PKG_OPTIONS:Mcamlp4)
.include "../../lang/camlp4/buildlink3.mk"
DEPENDS+=	ocaml-deriving-ocsigen>=0.8.1:../../devel/ocaml-deriving-ocsigen
PLIST.camlp4=	yes
DUNE_BUILD_PACKAGES+=	js_of_ocaml-camlp4
OPAM_INSTALL_FILES+=	js_of_ocaml-camlp4
.else
.endif
