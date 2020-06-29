# $NetBSD: options.mk,v 1.2 2020/06/29 10:19:26 yyamano Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-logs
PKG_SUPPORTED_OPTIONS=	fmt cmdliner lwt js_of_ocaml
PKG_SUGGESTED_OPTIONS=	fmt cmdliner lwt

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	browser cli fmt lwt

###
### fmt support
###
.if !empty(PKG_OPTIONS:Mfmt)
.include "../../devel/ocaml-fmt/buildlink3.mk"
PLIST.fmt=	yes
OCAML_TOPKG_FLAGS+=	--with-fmt true
.else
OCAML_TOPKG_FLAGS+= --with-fmt false
.endif

###
### cmdliner support
###
.if !empty(PKG_OPTIONS:Mcmdliner)
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
PLIST.cli=	yes
OCAML_TOPKG_FLAGS+=	--with-cmdliner true
.else
OCAML_TOPKG_FLAGS+= --with-cmdliner false
.endif

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
PLIST.lwt=	yes
OCAML_TOPKG_FLAGS+=	--with-lwt true
.else
OCAML_TOPKG_FLAGS+= --with-lwt false
.endif

###
### js_of_ocaml support
###
.if !empty(PKG_OPTIONS:Mjs_of_ocaml)
.include "../../devel/js_of_ocaml/buildlink3.mk"
PLIST.browser=	yes
OCAML_TOPKG_FLAGS+=	--with-js_of_ocaml true
.else
OCAML_TOPKG_FLAGS+= --with-js_of_ocaml false
.endif
