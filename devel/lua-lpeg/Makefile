# $NetBSD: Makefile,v 1.1.1.1 2013/01/06 13:49:26 alnsn Exp $
#

DISTNAME=	lpeg-0.10.2
PKGNAME=	${DISTNAME:S/lpeg/lua-lpeg/}
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://www.inf.puc-rio.br/~roberto/lpeg/
COMMENT=	Parsing Expression Grammars (PEGs) library for Lua
LICENSE=	mit

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
BUILD_TARGET=	lpeg.so

LPEG_PIC=	-fPIC
CFLAGS+=	${LPEG_PIC}

SUBST_CLASSES+=		pic
SUBST_STAGE.pic=	pre-build
SUBST_MESSAGE.pic=	Fixing PIC flag.
SUBST_FILES.pic=	makefile
SUBST_SED.pic=		-e 's/-fpic/${LPEG_PIC}/g'
SUBST_SED.pic+=		-e 's/^CFLAGS[ ]*=/CFLAGS+=/'

LPEG_HTML_DIR=		share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR} ${LPEG_HTML_DIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/lpeg.so \
	                ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/re.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html \
	                ${DESTDIR}${PREFIX}/${LPEG_HTML_DIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
