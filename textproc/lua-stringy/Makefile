# $NetBSD: Makefile,v 1.3 2025/01/21 14:35:47 nia Exp $

DISTNAME=	lua-stringy-0.7.0
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mdeneen/}
GITHUB_PROJECT=	lua-stringy
GITHUB_TAG=	v0.7-0

MAINTAINER=	pkgsrc-users@NetBSD.org
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

do-test:
	cd ${WRKSRC}/stringy && ${LUA_INTERPRETER} stringy_test.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
