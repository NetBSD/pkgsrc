# $NetBSD: Makefile,v 1.1.1.1 2004/05/08 01:54:18 minskim Exp $

DISTNAME=	UnFonts-ttf-20030907
PKGNAME=	${DISTNAME:S/UnFonts/un/}
CATEGORIES=	fonts korean
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/perky/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://chem.skku.ac.kr/~wkpark/project/font/UnFonts/
COMMENT=	Un series Korean TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
