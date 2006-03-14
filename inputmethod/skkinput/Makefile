# $NetBSD: Makefile,v 1.11 2006/03/14 01:14:29 jlam Exp $

DISTNAME=	skkinput-2.06.3
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skkinput2/1815/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://skkinput2.sourceforge.jp/
COMMENT=	X11 frontend for SKK

BUILD_DEFS+=	USE_INET6

USE_IMAKE=	YES

PLIST_SUBST+=	PKGBASE=${LOCALBASE:Q}
DEINSTALL_SRC=	# empty
INSTALL_SRC=	${PKGDIR}/INSTALL

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/README.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${PREFIX}/share/doc/skkinput

.include "../../mk/bsd.pkg.mk"
