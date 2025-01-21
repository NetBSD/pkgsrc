# $NetBSD: Makefile,v 1.3 2025/01/21 14:35:46 nia Exp $

DISTNAME=	lua-cmark-0.31.1
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}
GITHUB_PROJECT=	cmark-lua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgm/cmark-lua
COMMENT=	Lua wrapper for libcmark, the CommonMark parsing and rendering library
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/cmark-lua-${PKGVERSION_NOREV}

USE_TOOLS+=	gmake

BUILD_TARGET=	cmark.so

INSTALLATION_DIRS+=	${LUA_CDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/cmark

do-install:
	${INSTALL_LIB} ${WRKSRC}/cmark.so ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/cmark/builder.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/cmark/builder.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
