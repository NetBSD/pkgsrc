# $NetBSD: Makefile,v 1.1 2020/07/11 12:56:17 nia Exp $

DISTNAME=	luafun-0.1.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=luafun/}
GITHUB_PROJECT=	luafun
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/luafun/luafun
COMMENT=	Functional programming library for Lua
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fun.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/fun.lua
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/README.md

do-test:
	cd ${WRKSRC}/tests && ${LUA_INTERPRETER} ./runtest *.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
