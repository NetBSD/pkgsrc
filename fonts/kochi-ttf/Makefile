# $NetBSD: Makefile,v 1.1.1.1 2002/07/15 10:49:14 uebayasi Exp $

DISTNAME=	kochi-gothic-20020503
PKGNAME=	kochi-ttf-20020503
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.on.cs.keio.ac.jp/~yasu/linux/fonts/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	kochi-gothic-${KOCHI_VERSION}${EXTRACT_SUFX} \
		kochi-mincho-${KOCHI_VERSION}${EXTRACT_SUFX}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://www.on.cs.keio.ac.jp/~yasu/jp_fonts.html
COMMENT=	Free Japanese TrueType font by Yasuyuki Furukawa

DEPENDS+=	mkfontscale:../../fonts/mkfontscale

KOCHI_VERSION=	0.2.20020503

WRKSRC=		${WRKDIR}/kochi-gothic

NO_BUILD=	# Defined
USE_X11BASE=	# Defined

INSTALL_TMPL=	${FILESDIR}/install
DEINSTALL_TMPL=	${FILESDIR}/deinstall
FILES_SUBST+=	X11PREFIX=${X11PREFIX}
FILES_SUBST+=	X11FONTSSUBDIR=TrueType

post-extract:
	@${LN} ${WRKDIR}/kochi-mincho/fonts/kochi-mincho.ttf \
	    ${WRKSRC}/fonts

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/fonts/kochi-gothic.ttf \
	    ${X11PREFIX}/lib/X11/fonts/TrueType/kochi-gothic.ttf
	${INSTALL_DATA} ${WRKSRC}/fonts/kochi-mincho.ttf \
	    ${X11PREFIX}/lib/X11/fonts/TrueType/kochi-mincho.ttf
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/X11/fonts/TrueType

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
