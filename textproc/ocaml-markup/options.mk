# $NetBSD: options.mk,v 1.1 2018/11/27 17:20:09 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-markup
PKG_SUPPORTED_OPTIONS=	lwt
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=	lwt

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
