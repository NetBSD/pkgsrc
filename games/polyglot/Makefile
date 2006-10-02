# $NetBSD: Makefile,v 1.1.1.1 2006/10/02 20:06:07 rillig Exp $
#

DISTNAME=		polyglot_14
PKGNAME=		polyglot-1.4
CATEGORIES=		games
MASTER_SITES=		http://wbec-ridderkerk.nl/html/download/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://wbec-ridderkerk.nl/html/details/PolyGlot.html
COMMENT=		UCI to WB adapter (for chess engines)

WRKSRC=			${WRKDIR}/polyglot_14
BUILD_DIRS=		src
MAKE_FILE=		${FILESDIR}/Makefile
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin share/doc/polyglot share/examples/polyglot

post-extract:
	cp ${FILESDIR}/fruit.ini ${WRKSRC}/

SUBST_CLASSES+=		ini
SUBST_STAGE.ini=	post-configure
SUBST_FILES.ini=	fruit.ini
SUBST_SED.ini=		-e 's,@LOCALBASE@,${LOCALBASE},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/polyglot ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/polyglot/
	${INSTALL_DATA} ${WRKSRC}/fruit.ini ${PREFIX}/share/examples/polyglot/

.include "../../mk/bsd.pkg.mk"
