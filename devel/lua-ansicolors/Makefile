# $NetBSD: Makefile,v 1.1 2020/07/08 11:25:21 nia Exp $

DISTNAME=	ansicolors.lua-1.0.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/.lua//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikito/}
GITHUB_PROJECT=	ansicolors.lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/kikito/ansicolors.lua
COMMENT=	Simple Lua function for printing to the console in color
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/ansicolors.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/ansicolors.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
