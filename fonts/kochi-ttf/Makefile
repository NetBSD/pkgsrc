# $NetBSD: Makefile,v 1.14 2005/03/07 10:12:29 uebayasi Exp $

DISTNAME=	kochi-substitute-${KOCHI_VERSION}
PKGNAME=	kochi-ttf-${KOCHI_VERSION}
PKGREVISION=	4
CATEGORIES=	fonts japanese
MASTER_SITES=	http://osdn.dl.sourceforge.jp/efont/5411/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiki.fdiary.net/font/?kochi-alternative
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

KOCHI_VERSION=	20030809

NO_BUILD=	yes
USE_PKGINSTALL=	yes

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA} ${WRKSRC}/kochi-gothic-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/kochi-mincho-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-mincho.ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
