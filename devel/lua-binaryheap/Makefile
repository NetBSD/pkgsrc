# $NetBSD: Makefile,v 1.3 2022/02/19 20:43:41 nia Exp $

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

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/binaryheap.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/binaryheap.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
