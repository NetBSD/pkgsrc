# $NetBSD: Makefile,v 1.1.1.1 2004/07/23 00:32:16 minskim Exp $
#

DISTNAME=	ttf-alee_0.3
PKGNAME=	alee-ttf-0.3
CATEGORIES=	fonts korean
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/t/ttf-alee/

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://packages.debian.org/unstable/x11/ttf-alee/
COMMENT=	A Lee's Hangul truetype fonts

USE_X11BASE=    YES
NO_CONFIGURE=   YES
NO_BUILD=       YES

WRKSRC?=	${WRKDIR}/ttf-alee-0.3
FONTS_TTF_DIRS= ${PREFIX}/lib/X11/fonts/TTF
DOCDIR=         ${PREFIX}/share/doc/alee-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Copyright ${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
