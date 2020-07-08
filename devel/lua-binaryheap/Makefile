# $NetBSD: Makefile,v 1.2 2020/07/08 16:28:08 nia Exp $

DISTNAME=	lua-binaryheap-0.4
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tieske/}
GITHUB_PROJECT=	binaryheap.lua
GITHUB_TAG=	version_${PKGVERSION:S/./v/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tieske.github.io/binaryheap.lua/
COMMENT=	Binary heap implementation in Lua
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/binaryheap.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/binaryheap.lua

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION} --no-coverage

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
