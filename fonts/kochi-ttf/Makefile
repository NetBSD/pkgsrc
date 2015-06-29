# $NetBSD: Makefile,v 1.22 2015/06/29 11:06:46 ryoon Exp $

DISTNAME=	kochi-substitute-${KOCHI_VERSION}
PKGNAME=	kochi-ttf-${KOCHI_VERSION}
PKGREVISION=	6
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=efont/5411/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiki.fdiary.net/font/?kochi-alternative
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

KOCHI_VERSION=	20030809

NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fonts/X11/TTF
	${INSTALL_DATA} ${WRKSRC}/kochi-gothic-subst.ttf \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/TTF/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/kochi-mincho-subst.ttf \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/TTF/kochi-mincho.ttf

.include "../../mk/bsd.pkg.mk"
