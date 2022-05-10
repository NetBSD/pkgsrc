# $NetBSD: options.mk,v 1.8 2022/05/10 08:51:06 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.js_of_ocaml
PKG_SUPPORTED_OPTIONS=	lwt ocaml-tyxml
PKG_SUGGESTED_OPTIONS=	lwt ocaml-tyxml

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lwt tyxml

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
PLIST.lwt=	yes
DUNE_BUILD_PACKAGES+=	js_of_ocaml-lwt
OPAM_INSTALL_FILES+=	js_of_ocaml-lwt
.else
.endif

###
### TyXML support
###
.if !empty(PKG_OPTIONS:Mocaml-tyxml)
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../devel/ocaml-reactiveData/buildlink3.mk"
.include "../../textproc/ocaml-tyxml/buildlink3.mk"
PLIST.tyxml=	yes
DUNE_BUILD_PACKAGES+=	js_of_ocaml-tyxml
OPAM_INSTALL_FILES+=	js_of_ocaml-tyxml
.else
.endif
