# $NetBSD: Makefile,v 1.5 2020/07/02 10:26:19 nia Exp $

DISTNAME=	lua-cjson-2.1.0
PKGNAME=	${LUA_PKGPREFIX}-cjson-2.1.0
PKGREVISION=	2
CATEGORIES=	textproc lua
MASTER_SITES=	http://www.kyne.com.au/~mark/software/download/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://www.kyne.com.au/~mark/software/lua-cjson.php
COMMENT=	Lua CJSON provides JSON support for Lua
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_ENV+=	LUA_CDIR=${LUA_CDIR}

INSTALLATION_DIRS=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/cjson.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}


.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
