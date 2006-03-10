# $NetBSD: Makefile,v 1.10 2006/03/10 22:30:29 jlam Exp $

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
INSTALL_SRC=	${PKGDIR}/INSTALL
DEINSTALL_SRC=	# empty

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/README.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${PREFIX}/share/doc/skkinput

.include "../../mk/bsd.pkg.mk"
