# $NetBSD: Makefile,v 1.5 2020/07/08 16:33:31 nia Exp $

DISTNAME=	lustache-1.3.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	lustache
GITHUB_TAG=	v${PKGVERSION_NOREV}-0

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://olivinelabs.com/lustache/
COMMENT=	Logic-less mustache templates with Lua
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/lustache

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/lustache/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/lustache

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
