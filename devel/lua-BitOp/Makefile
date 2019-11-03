# $NetBSD: Makefile,v 1.7 2019/11/03 10:39:19 rillig Exp $

DISTNAME=	LuaBitOp-1.0.2
PKGNAME=	${DISTNAME:S/Lua/${LUA_PKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bitop.luajit.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitop.luajit.org/
COMMENT=	Lua module which adds bitwise operations on numbers
LICENSE=	mit

LUA_VERSIONS_INCOMPATIBLE=	53

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FLAGS+=	LUA_CDIR=${LUA_CDIR}
MAKE_FLAGS+=	LUA_DOCDIR=${LUA_DOCDIR}
MAKE_FLAGS+=	_LUA_DOT_VERSION=${_LUA_DOT_VERSION}
MAKE_FLAGS+=	INSTALLPATH=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx
.endif

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_DOCDIR}

TEST_TARGET=	test

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
