# $NetBSD: Makefile,v 1.3 2009/08/25 11:57:46 wiz Exp $
#

VERSION=	20061130
DISTNAME=	en_GB
PKGNAME=	hunspell-en_GB-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://en-gb.pyxidium.co.uk/dictionary/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://en-gb.pyxidium.co.uk/dictionary/
COMMENT=	British English dictionary for hunspell

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	hunspell-dictionaries/en_GB-${VERSION}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/hunspell share/doc/hunspell-en_GB

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/en_GB.* ${DESTDIR}${PREFIX}/share/hunspell
	${INSTALL_DATA} ${WRKSRC}/README_en_GB.txt \
		${DESTDIR}${PREFIX}/share/doc/hunspell-en_GB
	${INSTALL_DATA} ${WRKSRC}/dictionary.lst \
		${DESTDIR}${PREFIX}/share/doc/hunspell-en_GB

.include "../../mk/bsd.pkg.mk"
