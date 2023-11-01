# $NetBSD: options.mk,v 1.1 2023/11/01 15:37:07 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.hs-texmath
PKG_SUPPORTED_OPTIONS=	server
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

###
### Install a web server, texmath-server, that exposes a JSON API allowing
### conversion of individual formulas and batches of formulas.
###
.if !empty(PKG_OPTIONS:Mserver)
CONFIGURE_ARGS+=			-fserver
OPTPARSE_APPLICATIVE_EXECUTABLES+=	texmath-server
PLIST.server=				yes
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../www/hs-servant-server/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.endif
PLIST_VARS+=		server
