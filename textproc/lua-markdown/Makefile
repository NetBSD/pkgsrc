# $NetBSD: Makefile,v 1.1 2020/07/02 13:14:59 nia Exp $

DISTNAME=	lua-markdown-0.33
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=mpeterv/}
GITHUB_PROJECT=	markdown

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mpeterv/markdown
COMMENT=	Implementation of the Markdown text-to-html markup system in pure Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/markdown.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/markdown.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
