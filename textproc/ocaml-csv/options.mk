# $NetBSD: options.mk,v 1.4 2022/05/05 12:00:47 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-csv
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
OPAM_INSTALL_FILES+=	csv-lwt
OCAML_FINDLIB_DIRS+=	csv-lwt
.else
.endif
