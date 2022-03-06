# $NetBSD: Makefile,v 1.1 2022/03/06 09:16:22 nia Exp $

DISTNAME=	lua-enum-0.1.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//g}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=stefano-m/}
GITHUB_PROJECT=	lua-enum
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stefano-m.github.io/lua-enum/
COMMENT=	Enumerated Types for Lua
LICENSE=	mit

NO_BUILD=	yes
USE_LANGUAGES=	# none

LUA_USE_BUSTED=	yes

LUA_BUSTED_ARGS+=	tests/enum_spec.lua

INSTALLATION_DIRS+=	${LUA_LDIR}/enum

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/enum/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/enum

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
