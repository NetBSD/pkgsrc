# $NetBSD: Makefile,v 1.1 2020/07/02 17:46:26 nia Exp $

DISTNAME=	lua-arc4random-1.3.4
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	security lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikejsavage/}
GITHUB_PROJECT=	lua-arc4random
GITHUB_TAG=	v1.3-4

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/jgm/cmark-lua
COMMENT=	Lua wrapper for arc4random(3)
LICENSE=	mit

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/arc4random.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
