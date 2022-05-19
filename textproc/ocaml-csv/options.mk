# $NetBSD: options.mk,v 1.5 2022/05/19 08:22:33 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-csv
PKG_SUPPORTED_OPTIONS=	lwt
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=		lwt

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### Lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
PLIST.lwt=	yes
DUNE_BUILD_PACKAGES+=	csv-lwt
OPAM_INSTALL_FILES+=	csv-lwt
OCAML_FINDLIB_DIRS+=	csv-lwt
.else
.endif
