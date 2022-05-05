# $NetBSD: options.mk,v 1.1 2022/05/05 11:40:16 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml-cstruct
PKG_SUPPORTED_OPTIONS=	async lwt
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	async lwt

###
### async support
###
.if !empty(PKG_OPTIONS:Masync)
.include "../../devel/ocaml-async/buildlink3.mk"
.include "../../devel/ocaml-async_unix/buildlink3.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
PLIST.async=		yes
DUNE_BUILD_PACKAGES+=	cstruct-async
OPAM_INSTALL_FILES+=	cstruct-async
.endif

###
### lwt support
###
.if !empty(PKG_OPTIONS:Mlwt)
.include "../../devel/ocaml-lwt/buildlink3.mk"
PLIST.lwt=		yes
DUNE_BUILD_PACKAGES+=	cstruct-lwt
OPAM_INSTALL_FILES+=	cstruct-lwt
.endif
