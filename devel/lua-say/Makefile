# $NetBSD: Makefile,v 1.1 2020/07/08 15:46:37 nia Exp $

DISTNAME=	lua-say-1.3
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	say
GITHUB_TAG=	v${PKGVERSION_NOREV}-1

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/Olivine-Labs/say
COMMENT=	Lua string hashing library, useful for internationalization
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${LUA_LDIR}/say

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/init.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/say/init.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
