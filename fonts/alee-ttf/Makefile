# $NetBSD: Makefile,v 1.22 2013/04/06 03:45:13 rodent Exp $
#

DISTNAME=	ttf-alee_12
PKGNAME=	${DISTNAME:S/ttf-alee_/alee-ttf-/}
CATEGORIES=	fonts korean
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-alee/}

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://packages.debian.org/unstable/x11/ttf-alee
COMMENT=	A. Lee's Hangul truetype fonts
LICENSE=	artistic

NO_CONFIGURE=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTS_DIRS.ttf=	lib/X11/fonts/TTF
FONTS_DIRS.x11=	lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF share/doc/alee-ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/alee-ttf

.include "../../mk/bsd.pkg.mk"
