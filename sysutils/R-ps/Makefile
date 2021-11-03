# $NetBSD: Makefile,v 1.4 2021/11/03 13:59:13 mef Exp $

R_PKGNAME=	ps
R_PKGVER=	1.6.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	List, query, manipulate system processes
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr

# ps/src/Makevars.in:      $(CC) $(CFLAGS)  -Wall px.c -o px
#                          PKG_LIBS = @LIBS@
SUBST_CLASSES+=	relro
SUBST_MESSAGE.relro=	RELRO (partial) support
SUBST_FILES.relro=	src/Makevars.in
SUBST_STAGE.relro=	pre-configure
SUBST_SED.relro=	-e '/Wall px.c/s/CC)/CC) -Wl,-z,relro /'
SUBST_SED.relro+=	-e 's/@LIBS@/-Wl,-z,relro /'

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
