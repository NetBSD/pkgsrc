# $NetBSD: Makefile,v 1.17 2019/07/20 22:46:47 wiz Exp $

PKGNAME=		libprelude-lua-${VERSION}
PKGREVISION=		13
COMMENT=                Lua bindings to LibPrelude

LUA_VERSIONS_ACCEPTED=	51

.include "../../security/libprelude/Makefile.common"

CONFIGURE_ARGS+=	--with-lua

BUILD_DIRS=		bindings/lua

PKG_OPTIONS_VAR=	PKG_OPTIONS.libprelude
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS=			-O0 -ggdb
.endif

.include "../../devel/libltdl/convenience.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
