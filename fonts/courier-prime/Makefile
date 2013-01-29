# $NetBSD: Makefile,v 1.1 2013/01/29 07:57:18 wiz Exp $
#

DISTNAME=	courier-prime
# version number comes from include readme.
PKGNAME=	${DISTNAME}-1.203
CATEGORIES=	fonts
MASTER_SITES=	http://quoteunquoteapps.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quoteunquoteapps.com/courierprime/
COMMENT=	Fixed-width font designed for screenplays
LICENSE=	open-font-license

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_LANGUAGES=	# none

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}
INSTALLATION_DIRS+=	share/doc/courier-prime

post-extract:
	cd ${WRKDIR} && mv "Courier Prime" ${DISTNAME}

do-configure:
do-build:
do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/courier-prime

.include "../../mk/bsd.pkg.mk"
