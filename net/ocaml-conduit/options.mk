# $NetBSD: options.mk,v 1.3 2022/05/11 10:40:58 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-conduit
PKG_SUPPORTED_OPTIONS=	async lwt
PKG_SUGGESTED_OPTIONS=	async lwt

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	async lwt

###
### async support
###
.if !empty(PKG_OPTIONS:Masync)
.include "../../devel/ocaml-async/buildlink3.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-ppx_here/buildlink3.mk"
DUNE_BUILD_PACKAGES+=	conduit-async
OPAM_INSTALL_FILES+=	conduit-async
PLIST.async=	yes
.endif

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
DUNE_BUILD_PACKAGES+=	conduit-lwt conduit-lwt-unix
OPAM_INSTALL_FILES+=	conduit-lwt conduit-lwt-unix
PLIST.lwt=	yes
.endif
