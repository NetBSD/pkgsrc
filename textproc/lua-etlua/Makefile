# $NetBSD: Makefile,v 1.1 2020/07/02 17:30:23 nia Exp $

DISTNAME=	lua-etlua-1.3.0
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=leafo/}
GITHUB_PROJECT=	etlua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/leafo/etlua
COMMENT=	Embedded templates for Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/etlua.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/etlua.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
