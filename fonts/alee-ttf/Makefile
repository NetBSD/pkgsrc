# $NetBSD: Makefile,v 1.10 2005/10/12 19:34:14 minskim Exp $
#

DISTNAME=	ttf-alee_5.4
PKGNAME=	alee-ttf-5.4
CATEGORIES=	fonts korean
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/t/ttf-alee/

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://packages.debian.org/unstable/x11/ttf-alee/
COMMENT=	A Lee's Hangul truetype fonts

USE_X11BASE=    YES
NO_CONFIGURE=   YES
NO_BUILD=       YES

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTS_TTF_DIRS= ${PREFIX}/lib/X11/fonts/TTF
DOCDIR=         ${PREFIX}/share/doc/alee-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
