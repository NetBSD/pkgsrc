# $NetBSD: Makefile,v 1.8 2026/11/27 07:29:21 wiz Exp $

DISTNAME=	lua-utf8-0.3.0
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=starwing/}
GITHUB_PROJECT=	luautf8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/starwing/luautf8
COMMENT=	UTF-8 module for Lua 5.x
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/lua-utf8.so \
	    ${DESTDIR}${PREFIX}/${LUA_CDIR}/lua-utf8.so

# from .github/workflows/test.yml
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${LUA_INTERPRETER} test.lua && ${LUA_INTERPRETER} test_pm.lua && ${LUA_INTERPRETER} test_compat.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
