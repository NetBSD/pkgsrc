# $NetBSD: Makefile,v 1.1 2020/08/06 22:56:52 joerg Exp $

DISTNAME=	epnf-0.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=siffiejoe/}
GITHUB_PROJECT=	lua-luaepnf
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://siffiejoe.github.io/lua-luaepnf/
COMMENT=	Abstract Syntax Tree support library for Lua
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/epnf.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
