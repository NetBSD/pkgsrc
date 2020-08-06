# $NetBSD: Makefile,v 1.2 2020/08/06 23:22:13 joerg Exp $

DISTNAME=	lua-cosmo-16.06.04
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mascarenhas/}
GITHUB_PROJECT=	cosmo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mascarenhas/cosmo/
COMMENT=	Lua template engine
LICENSE=	mit

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${LUA_LDIR}/cosmo

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/cosmo.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/cosmo/*.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}/cosmo

do-test:
	cd ${WRKSRC}/tests && ${LUA_INTERPRETER} test_cosmo.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
