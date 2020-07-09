# $NetBSD: Makefile,v 1.1 2020/07/09 11:14:01 nia Exp $

DISTNAME=	lua-inifile-1.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=bartbes/}
GITHUB_PROJECT=	inifile
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://docs.bartbes.com/inifile
COMMENT=	Lua library for parsing and writing .ini files
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/inifile.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/inifile.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
