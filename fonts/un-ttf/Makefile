# $NetBSD: Makefile,v 1.2 2004/08/04 22:56:02 minskim Exp $

DISTNAME=	un-ttf-20040804
CATEGORIES=	fonts korean
MASTER_SITES=	http://chem.skku.ac.kr/~wkpark/project/font/UnFonts/20040804/
DISTFILES=	UnBatang.ttf UnBatangBold.ttf UnBom.ttf UnDotum.ttf	\
		UnDotumBold.ttf UnGraphic.ttf UnGungseo.ttf UnPen.ttf	\
		UnPenheulim.ttf UnPilgi.ttf UnPilgiBold.ttf		\
		UnShinmun.ttf UnTaza.ttf UnYetgul.ttf    

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://chem.skku.ac.kr/~wkpark/project/font/UnFonts/
COMMENT=	Un series Korean TrueType fonts

DIST_SUBDIR=	${DISTNAME}
USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
