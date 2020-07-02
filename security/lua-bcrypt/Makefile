# $NetBSD: Makefile,v 1.1 2020/07/02 17:59:02 nia Exp $

DISTNAME=	lua-bcrypt-2.1.5
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	security lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikejsavage/}
GITHUB_PROJECT=	lua-bcrypt
GITHUB_TAG=	v2.1-5

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mikejsavage/lua-bcrypt
COMMENT=	Lua wrapper for the bcrypt password hashing function
LICENSE=	isc

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/bcrypt.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
