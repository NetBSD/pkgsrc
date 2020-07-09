# $NetBSD: Makefile,v 1.1 2020/07/09 10:48:58 nia Exp $

DISTNAME=	mmdblua-0.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-/-/1}
CATEGORIES=	geography lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
GITHUB_PROJECT=	mmdblua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daurnimator/mmdblua
COMMENT=	MaxMind Geolocation database format parser for Lua
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/${PKGNAME_NOREV}
INSTALLATION_DIRS+=	${LUA_LDIR}/mmdb

do-install:
	${INSTALL_DATA} ${WRKSRC}/example.lua \
		${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/example.lua
	${INSTALL_DATA} ${WRKSRC}/mmdb/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/mmdb

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
