# $NetBSD: Makefile,v 1.6 2003/08/18 06:54:09 uebayasi Exp $

DISTNAME=	kochi-gothic-20020503
PKGNAME=	kochi-ttf-20020503
WRKSRC=		${WRKDIR}/kochi-gothic
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.on.cs.keio.ac.jp/~yasu/linux/fonts/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	kochi-gothic-${KOCHI_VERSION}${EXTRACT_SUFX} \
		kochi-mincho-${KOCHI_VERSION}${EXTRACT_SUFX}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.on.cs.keio.ac.jp/~yasu/jp_fonts.html
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

DEPENDS+=	mkfontscale>=20020524:../../fonts/mkfontscale

KOCHI_VERSION=	0.2.20020503

NO_BUILD=	yes
USE_X11BASE=	yes
USE_PKGINSTALL=	yes

INSTALL_TMPL=	${FILESDIR}/install
DEINSTALL_TMPL=	${FILESDIR}/deinstall
FILES_SUBST+=	X11PREFIX=${X11PREFIX}
FILES_SUBST+=	X11FONTSSUBDIR=TrueType

post-extract:
	@${LN} ${WRKDIR}/kochi-mincho/fonts/kochi-mincho.ttf \
	    ${WRKSRC}/fonts

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/fonts/kochi-gothic.ttf \
	    ${PREFIX}/lib/X11/fonts/TrueType/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/fonts/kochi-mincho.ttf \
	    ${PREFIX}/lib/X11/fonts/TrueType/kochi-mincho.ttf

.include "../../mk/bsd.pkg.mk"
