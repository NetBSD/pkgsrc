# $NetBSD: Makefile,v 1.1 2014/03/22 13:44:02 imil Exp $

DISTNAME=	lua-cjson-2.1.0
PKGNAME=	${LUA_PKGPREFIX}-cjson-2.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.kyne.com.au/~mark/software/download/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://www.kyne.com.au/~mark/software/lua-cjson.php
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
