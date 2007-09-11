# $NetBSD: Makefile,v 1.1.1.1 2007/09/11 18:37:27 wiz Exp $
#

VERSION=	20070829
# bogus by purpose
DISTNAME=	hunspell-de-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://www.j3e.de/hunspell/
DISTFILES=	de_AT-${VERSION}.zip de_CH-${VERSION}.zip de_DE-${VERSION}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.j3e.de/ispell/igerman98/
COMMENT=	German dictionaries for hunspell

DIST_SUBDIR=	hunspell-dictionaries
# don't want -L
EXTRACT_OPTS_ZIP=	-aqo

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-de

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/de* ${PREFIX}/share/hunspell
	${INSTALL_DATA} ${WRKSRC}/[CR]* ${PREFIX}/share/doc/hunspell-de
	${INSTALL_DATA} ${WRKSRC}/dict* ${PREFIX}/share/doc/hunspell-de

.include "../../mk/bsd.pkg.mk"
