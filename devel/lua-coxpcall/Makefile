# $NetBSD: Makefile,v 1.1.1.1 2016/06/05 09:55:45 alnsn Exp $

DISTNAME=	coxpcall-1.16.0
PKGNAME=	${DISTNAME:S/coxpcall/${LUA_PKGPREFIX}-coxpcall/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION:S/./_/g}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://keplerproject.github.io/coxpcall
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
