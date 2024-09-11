# $NetBSD: Makefile,v 1.2 2024/09/11 19:17:57 yhardy Exp $

DISTNAME=	ftcsv-1.4.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=FourierTransformer/}
GITHUB_PROJECT=	ftcsv

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FourierTransformer/ftcsv
COMMENT=	Fast csv library written in pure Lua
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-cjson-[0-9]*:../../textproc/lua-cjson

NO_BUILD=	yes
USE_LANGUAGES=	# none

LUA_USE_BUSTED=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/ftcsv.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
