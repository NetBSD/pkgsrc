# $NetBSD: Makefile,v 1.8 2015/02/03 22:59:01 alnsn Exp $
#

DISTNAME=	lpeg-0.12.1
PKGNAME=	${DISTNAME:S/lpeg/${LUA_PKGPREFIX}-lpeg/}
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://www.inf.puc-rio.br/~roberto/lpeg/
COMMENT=	Parsing Expression Grammars (PEGs) library for Lua
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
TEST_TARGET=	test

.if ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx
.else
BUILD_TARGET=	linux
.endif

REPLACE_LUA+=	test.lua

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR} ${LUA_DOCDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/lpeg.so \
	                ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/re.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/lpeg-128.gif \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/HISTORY \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

.include "../../lang/lua/module.mk"
.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
