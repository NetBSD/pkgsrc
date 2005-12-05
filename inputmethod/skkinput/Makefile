# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:24 rillig Exp $

DISTNAME=	skkinput-2.06.3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://osdn.dl.sourceforge.jp/skkinput2/1815/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://skkinput2.sourceforge.jp/
COMMENT=	X11 frontend for SKK

BUILD_DEFS+=	USE_INET6

USE_IMAKE=	YES

PLIST_SUBST+=	PKGBASE=${LOCALBASE:Q}

DESCR_SRC=	${WRKDIR}/DESCR
INSTALL_FILE=	${WRKDIR}/INSTALL

post-build:
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/DESCR	>${DESCR_SRC}
	${SED} 's#@PKGBASE@#${LOCALBASE}#g' ${PKGDIR}/INSTALL	>${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/README.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${PREFIX}/share/doc/skkinput
	${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
