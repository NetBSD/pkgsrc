# $NetBSD: Makefile,v 1.1 2020/07/08 16:00:22 nia Exp $

DISTNAME=	dkjson-2.5
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	http://dkolf.de/src/dkjson-lua.fsl/tarball/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dkolf.de/src/dkjson-lua.fsl/home
COMMENT=	JSON module written in Lua
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/dkjson.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/dkjson.lua

do-test:
	cd ${WRKSRC} && ${LUA_INTERPRETER} jsontest.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
