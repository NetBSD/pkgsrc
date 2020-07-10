# $NetBSD: Makefile,v 1.1 2020/07/10 10:26:59 nia Exp $

DISTNAME=	luacov-0.14.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
CATEGORIES=	lua devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=	luacov
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keplerproject.github.io/luacov/
COMMENT=	Simple coverage analyzer for Lua scripts
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

PLIST_SUBST+=	LUADOTVER=${_LUA_DOT_VERSION}

REPLACE_LUA+=	src/bin/luacov

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${LUA_LDIR}/luacov
INSTALLATION_DIRS+=	${LUA_LDIR}/luacov/reporter
INSTALLATION_DIRS+=	${LUA_DOCDIR}/doc/modules

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/luacov \
		${DESTDIR}${PREFIX}/bin/luacov${_LUA_DOT_VERSION}
	${INSTALL_DATA} ${WRKSRC}/src/luacov.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/luacov/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacov
	${INSTALL_DATA} ${WRKSRC}/src/luacov/reporter/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/luacov/reporter
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.css *.png \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	cd ${WRKSRC}/doc/doc && ${INSTALL_DATA} *.html *.css \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/doc
	cd ${WRKSRC}/doc/doc/modules && ${INSTALL_DATA} *.html \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/doc/modules

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
