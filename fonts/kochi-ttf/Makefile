# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:10 joerg Exp $

DISTNAME=	kochi-substitute-${KOCHI_VERSION}
PKGNAME=	kochi-ttf-${KOCHI_VERSION}
PKGREVISION=	5
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=efont/5411/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiki.fdiary.net/font/?kochi-alternative
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

KOCHI_VERSION=	20030809

NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA} ${WRKSRC}/kochi-gothic-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/kochi-mincho-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-mincho.ttf

.include "../../mk/bsd.pkg.mk"
