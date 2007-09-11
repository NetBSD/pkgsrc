# $NetBSD: Makefile,v 1.1.1.1 2007/09/11 18:38:15 wiz Exp $
#

VERSION=	20060207
DISTNAME=	en_US
PKGNAME=	hunspell-en_US-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/dictionaries/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.services.openoffice.org/wiki/Dictionaries
COMMENT=	US American English dictionaries for hunspell

DIST_SUBDIR=	hunspell-dictionaries/en_US-${VERSION}
# don't want -L
EXTRACT_OPTS_ZIP=	-aqo

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-en_US

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/en_US.* ${PREFIX}/share/hunspell
	${INSTALL_DATA} ${WRKSRC}/README_en_US.txt \
		${PREFIX}/share/doc/hunspell-en_US

.include "../../mk/bsd.pkg.mk"
