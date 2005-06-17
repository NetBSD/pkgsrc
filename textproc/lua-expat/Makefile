# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:37 jlam Exp $
#

DISTNAME=	luaexpat-1.0a
PKGNAME=	${DISTNAME:S/lua/lua-/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.keplerproject.org/luaexpat/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.tecgraf.puc-rio.br/~diego/luasocket/new/
COMMENT=	XML parser for LUA based on expat

USE_TOOLS+=	gmake
MAKEFILE=	makefile

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblxp.so ${PREFIX}/lib/liblualxp.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lua
	${INSTALL_DATA} ${WRKSRC}/test.lua ${PREFIX}/share/examples/lua/lxp.lua

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
