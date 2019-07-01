# $NetBSD: options.mk,v 1.1 2019/07/01 16:08:51 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-git
PKG_SUPPORTED_OPTIONS=	unix http
PKG_SUGGESTED_OPTIONS=	unix http

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	unix http

###
### http support
###
.if !empty(PKG_OPTIONS:Mhttp)
.include "../../www/ocaml-cohttp/buildlink3.mk"
PLIST.http=	yes
DUNE_BUILD_PACKAGES+=	git-http
OPAM_INSTALL_FILES+=	git-http
.endif

###
### unix support
###
.if !empty(PKG_OPTIONS:Munix)
.if !empty(PKG_OPTIONS:Mhttp) # unix needs http
.include "../../www/ocaml-cohttp/buildlink3.mk"
.include "../../time/ocaml-mtime/buildlink3.mk"
PLIST.unix=	yes
DUNE_BUILD_PACKAGES+=	git-unix
OPAM_INSTALL_FILES+=	git-unix
.else
PKG_FAIL_REASON+= "unix option needs http"
.endif
.endif
