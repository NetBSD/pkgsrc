# $NetBSD: Makefile,v 1.1.1.1 2009/02/12 01:45:01 minskim Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}

COMMENT=		Standard library for Lua programming language

INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../mk/bsd.pkg.mk"
