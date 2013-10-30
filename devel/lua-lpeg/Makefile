# $NetBSD: Makefile,v 1.4 2013/10/30 06:03:37 dholland Exp $
#

DISTNAME=	lpeg-0.12
PKGNAME=	${DISTNAME:S/lpeg/${LUA_PKGPREFIX}-lpeg/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://www.inf.puc-rio.br/~roberto/lpeg/
COMMENT=	Parsing Expression Grammars (PEGs) library for Lua
LICENSE=	mit

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
BUILD_TARGET=	linux
TEST_TARGET=	test

SUBST_CLASSES+=		inc-path
SUBST_STAGE.inc-path=	pre-build
SUBST_MESSAGE.inc-path=	Fixing Lua include path.
SUBST_FILES.inc-path=	makefile
SUBST_SED.inc-path=	-e 's|^LUADIR[ \].*|LUADIR = ${PREFIX}/include|'

SUBST_CLASSES+=		interp
SUBST_STAGE.interp=	pre-build
SUBST_MESSAGE.interp=	Fixing Lua include path.
SUBST_FILES.interp=	test.lua
SUBST_SED.interp=	-e 's|^\#!.*|\#!${PREFIX}/bin/lua|'

LPEG_HTML_DIR=		share/doc/lua-lpeg
INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR} ${LPEG_HTML_DIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/lpeg.so \
	                ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/re.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html \
	                ${DESTDIR}${PREFIX}/${LPEG_HTML_DIR}
	${INSTALL_DATA} ${WRKSRC}/lpeg-128.gif \
	                ${DESTDIR}${PREFIX}/${LPEG_HTML_DIR}
	${INSTALL_DATA} ${WRKSRC}/HISTORY \
	                ${DESTDIR}${PREFIX}/${LPEG_HTML_DIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
