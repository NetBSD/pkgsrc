# $NetBSD: Makefile,v 1.5 2020/07/14 12:21:01 nia Exp $

DISTNAME=	coxpcall-1.17.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=	coxpcall
GITHUB_TAG=	v${PKGVERSION:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keplerproject.github.io/coxpcall
COMMENT=	Module to encapsulate protected calls with a coroutine based loop
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_DOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/coxpcall.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* \
	    ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
