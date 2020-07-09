# $NetBSD: Makefile,v 1.2 2020/07/09 15:03:35 nia Exp $

DISTNAME=	loadkit-1.1.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=leafo/}
GITHUB_PROJECT=	loadkit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leafo/loadkit
COMMENT=	Allows you to load arbitrary files within the Lua package path
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_DOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/loadkit.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/loadkit.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
