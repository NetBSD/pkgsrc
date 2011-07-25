# $NetBSD: Makefile,v 1.2 2011/07/25 20:10:50 cheusov Exp $

.include "../../devel/lua-stdlib/Makefile.common"

PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
PKGREVISION=		1
COMMENT=		Standard library for Lua programming language

DEPENDS+=		lua-lrexlib-pcre-[0-9]*:../../devel/lua-lrexlib-pcre
INSTALLATION_DIRS+=	${LUA_LDIR}

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/modules/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../mk/bsd.pkg.mk"
