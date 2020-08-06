# $NetBSD: Makefile,v 1.1 2020/08/06 22:47:16 joerg Exp $

DISTNAME=	linenoise-0.9
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoelzro/}
GITHUB_PROJECT=	lua-linenoise
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoelzro/lua-linenoise/
COMMENT=	Lua binding for linenoise
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_CDIR}

USE_TOOLS+=	gmake

BUILD_TARGET=

do-install:
	${INSTALL_DATA} ${WRKSRC}/linenoise.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
