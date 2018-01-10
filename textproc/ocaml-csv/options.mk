# $NetBSD: options.mk,v 1.1 2018/01/10 16:46:03 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-csv
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
JBUILDER_BUILD_PACKAGES+=	csv-lwt
OPAM_INSTALL_FILES+=	csv-lwt
.else
.endif
