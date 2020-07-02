# $NetBSD: Makefile,v 1.4 2020/07/02 10:26:16 nia Exp $

DISTNAME=	coxpcall-1.16.0
PKGNAME=	${DISTNAME:S/coxpcall/${LUA_PKGPREFIX}-coxpcall/}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION:S/./_/g}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keplerproject.github.io/coxpcall
COMMENT=	Module to encapsulate protected calls with a coroutine based loop
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_DOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/coxpcall.lua \
	    ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* \
	    ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
