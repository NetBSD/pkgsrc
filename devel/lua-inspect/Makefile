# $NetBSD: Makefile,v 1.4 2025/01/21 11:00:11 nia Exp $

DISTNAME=	lua-inspect-3.1.3
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikito/}
GITHUB_PROJECT=	inspect.lua
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kikito/inspect.lua
COMMENT=	Human-readable representation of Lua tables
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/inspect.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
