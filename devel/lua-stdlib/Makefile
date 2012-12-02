# $NetBSD: Makefile,v 1.3 2012/12/02 09:26:08 cheusov Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
COMMENT=		Standard library for Lua programming language
MAINTAINER=		cheusov@NetBSD.org

INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../mk/bsd.pkg.mk"
