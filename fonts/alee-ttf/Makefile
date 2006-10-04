# $NetBSD: Makefile,v 1.17 2006/10/04 21:39:31 wiz Exp $
#

DISTNAME=	ttf-alee_7.3
PKGNAME=	${DISTNAME:S/ttf-alee_/alee-ttf-/}
CATEGORIES=	fonts korean
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-alee/}

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://packages.debian.org/unstable/x11/ttf-alee
COMMENT=	A Lee's Hangul truetype fonts

USE_X11BASE=    YES
NO_CONFIGURE=   YES
NO_BUILD=       YES

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTS_DIRS.ttf= ${PREFIX}/lib/X11/fonts/TTF
DOCDIR=         ${PREFIX}/share/doc/alee-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
