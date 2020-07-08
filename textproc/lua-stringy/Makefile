# $NetBSD: Makefile,v 1.1 2020/07/08 11:54:53 nia Exp $

DISTNAME=	lua-stringy-0.6.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mdeneen/}
GITHUB_PROJECT=	lua-stringy
GITHUB_TAG=	v0.6-1

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mdeneen/lua-stringy
COMMENT=	Fast Lua string operations
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

BUILD_DIRS=	stringy

MAKE_FLAGS+=	LUA_PC=lua-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

INSTALLATION_DIRS+=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/stringy/stringy.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/stringy.so

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
