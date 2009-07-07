# $NetBSD: Makefile,v 1.13 2009/07/07 21:10:16 joerg Exp $
#

DISTNAME=	luaexpat-1.0a
PKGNAME=	${DISTNAME:S/lua/lua-/}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://www.keplerproject.org/luaexpat/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.keplerproject.org/luaexpat/
COMMENT=	XML parser for LUA based on expat

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
MAKE_FILE=	makefile

CFLAGS+=	-fPIC

INSTALLATION_DIRS=	lib share/examples/lua

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblxp.so ${DESTDIR}${PREFIX}/lib/liblualxp.so
	${INSTALL_DATA} ${WRKSRC}/test.lua ${DESTDIR}${PREFIX}/share/examples/lua/lxp.lua

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
