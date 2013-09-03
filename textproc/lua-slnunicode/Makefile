# $NetBSD: Makefile,v 1.1 2013/09/03 16:18:41 ryoon Exp $

DISTNAME=	slnunicode-1.1apl1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/LuaDist/slnunicode/
COMMENT=	Unicode library for Lua
#LICENSE=	# TODO: (see mk/license.mk)

FETCH_USING=	curl

BUILD_TARGET=	unicode.so

FIND_PREFIX:=	LUADIR=lua
.include "../../mk/find-prefix.mk"

MAKE_ENV+=	LUADIR=${LUADIR}

INSTALLATION_DIRS=	${LUA_CDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/unicode.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
