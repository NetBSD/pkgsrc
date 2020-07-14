# $NetBSD: Makefile,v 1.2 2020/07/14 12:44:16 nia Exp $

DISTNAME=	luassert-1.8.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	luassert
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Olivine-Labs/luassert
COMMENT=	Lua Assertions Extension library
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/matchers
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/formatters
INSTALLATION_DIRS+=	${LUA_LDIR}/luassert/languages

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert
	${INSTALL_DATA} ${WRKSRC}/src/matchers/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/matchers
	${INSTALL_DATA} ${WRKSRC}/src/formatters/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/formatters
	${INSTALL_DATA} ${WRKSRC}/src/languages/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/luassert/languages

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
