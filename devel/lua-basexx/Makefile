# $NetBSD: Makefile,v 1.3 2022/02/19 20:43:41 nia Exp $

DISTNAME=	lua-basexx-0.4.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=aiq/}
GITHUB_PROJECT=	basexx
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiq/basexx
COMMENT=	BaseXX encoding and decoding library for Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
NO_BUILD=	yes

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/basexx.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/basexx.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
