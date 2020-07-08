# $NetBSD: Makefile,v 1.1 2020/07/08 12:52:07 nia Exp $

DISTNAME=	mediator_lua-1.1.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/_lua//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Olivine-Labs/}
GITHUB_PROJECT=	mediator_lua
GITHUB_TAG=	v${PKGVERSION_NOREV}-0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://olivinelabs.com/mediator_lua/
COMMENT=	Mediator pattern implementation for pub-sub management
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/mediator.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/mediator.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
