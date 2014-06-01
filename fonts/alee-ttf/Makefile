# $NetBSD: Makefile,v 1.23 2014/06/01 16:35:32 wiz Exp $
#

DISTNAME=	ttf-alee_12
PKGNAME=	${DISTNAME:S/ttf-alee_/alee-ttf-/}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-alee/}

MAINTAINER=	fox9@netb.co.kr
HOMEPAGE=	http://packages.debian.org/unstable/x11/ttf-alee
COMMENT=	A. Lee's Hangul truetype fonts
LICENSE=	artistic

NO_CONFIGURE=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTS_DIRS.ttf=	share/fonts/X11/TTF
FONTS_DIRS.x11=	share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF share/doc/alee-ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/alee-ttf

.include "../../mk/bsd.pkg.mk"
