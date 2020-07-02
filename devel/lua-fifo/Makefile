# $NetBSD: Makefile,v 1.1 2020/07/02 14:52:49 nia Exp $

DISTNAME=	lua-fifo-0.2
PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=daurnimator/}
GITHUB_PROJECT=	fifo.lua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daurnimator/fifo.lua
COMMENT=	FIFO library for Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fifo.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/fifo.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
