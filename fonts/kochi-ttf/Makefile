# $NetBSD: Makefile,v 1.10 2004/06/15 02:35:11 minskim Exp $

DISTNAME=	kochi-substitute-${KOCHI_VERSION}
PKGNAME=	kochi-ttf-${KOCHI_VERSION}
PKGREVISION=	2
CATEGORIES=	fonts japanese
MASTER_SITES=	http://osdn.dl.sourceforge.jp/efont/5411/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiki.fdiary.net/font/?kochi-alternative
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

KOCHI_VERSION=	20030809

NO_BUILD=	yes
USE_X11BASE=	yes
USE_PKGINSTALL=	yes

INSTALL_TMPL=	${FILESDIR}/install
DEINSTALL_TMPL=	${FILESDIR}/deinstall
FILES_SUBST+=	X11PREFIX=${X11PREFIX}
FILES_SUBST+=	X11FONTSSUBDIR=TTF

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA} ${WRKSRC}/kochi-gothic-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/kochi-mincho-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TTF/kochi-mincho.ttf

.include "../../mk/bsd.pkg.mk"
