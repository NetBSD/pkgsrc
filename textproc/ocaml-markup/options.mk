# $NetBSD: options.mk,v 1.2 2019/11/04 21:43:39 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-markup
PKG_SUPPORTED_OPTIONS=	lwt
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=		lwt

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### Camlp4 support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
PLIST.lwt=	yes
DUNE_BUILD_PACKAGES+=	markup-lwt
OPAM_INSTALL_FILES+=	markup-lwt
.else
.endif
