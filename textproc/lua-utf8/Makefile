# $NetBSD: Makefile,v 1.6 2023/02/01 12:32:33 nia Exp $

DISTNAME=	lua-utf8-0.1.5
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=starwing/}
GITHUB_PROJECT=	luautf8

MAINTAINER=	nia@NetBSD.org
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

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
