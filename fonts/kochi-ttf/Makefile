# $NetBSD: Makefile,v 1.7 2004/01/05 09:00:58 uebayasi Exp $

DISTNAME=	kochi-substitute-${KOCHI_VERSION}
PKGNAME=	kochi-ttf-${KOCHI_VERSION}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.on.cs.keio.ac.jp/~yasu/linux/fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.on.cs.keio.ac.jp/~yasu/jp_fonts.html
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

DEPENDS+=	mkfontscale>=20020524:../../fonts/mkfontscale

KOCHI_VERSION=	20030809

NO_BUILD=	yes
USE_X11BASE=	yes
USE_PKGINSTALL=	yes

INSTALL_TMPL=	${FILESDIR}/install
DEINSTALL_TMPL=	${FILESDIR}/deinstall
FILES_SUBST+=	X11PREFIX=${X11PREFIX}
FILES_SUBST+=	X11FONTSSUBDIR=TrueType

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/kochi-gothic-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TrueType/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/kochi-mincho-subst.ttf \
	    ${PREFIX}/lib/X11/fonts/TrueType/kochi-mincho.ttf

.include "../../mk/bsd.pkg.mk"
