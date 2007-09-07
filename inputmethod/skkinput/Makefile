# $NetBSD: Makefile,v 1.14 2007/09/07 22:12:12 jlam Exp $

DISTNAME=	skkinput-2.06.3
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=skkinput2/1815/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://skkinput2.sourceforge.jp/
COMMENT=	X11 frontend for SKK

BUILD_DEFS+=	IPV6_READY

USE_IMAKE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/README.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/FAQ.jis	${PREFIX}/share/doc/skkinput
	${INSTALL_DATA} ${WRKSRC}/BUGS.jis	${PREFIX}/share/doc/skkinput

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
