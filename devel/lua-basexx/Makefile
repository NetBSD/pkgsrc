# $NetBSD: Makefile,v 1.1 2020/07/02 14:36:29 nia Exp $

DISTNAME=	lua-basexx-0.4.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
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

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/basexx.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/basexx.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
