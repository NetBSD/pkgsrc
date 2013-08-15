# $NetBSD: Makefile,v 1.4 2013/08/15 06:32:06 obache Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
PKGREVISION=		1
COMMENT=		Standard library for Lua programming language
MAINTAINER=		cheusov@NetBSD.org

INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../mk/bsd.pkg.mk"
