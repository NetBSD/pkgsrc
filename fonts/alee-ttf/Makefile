# $NetBSD: Makefile,v 1.12 2005/11/23 05:49:59 minskim Exp $
#

DISTNAME=	ttf-alee_6.0
PKGNAME=	${DISTNAME:S/ttf-alee_/alee-ttf-/}
CATEGORIES=	fonts korean
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-alee/}

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
