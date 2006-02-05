# $NetBSD: Makefile,v 1.17 2006/02/05 23:10:09 joerg Exp $
#

DISTNAME=		kanjipad-2.0.0
PKGREVISION=	3
CATEGORIES=		misc
MASTER_SITES=		http://fishsoup.net/software/kanjipad/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_TOOLS+=		gmake perl pkg-config

.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjipad
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kanjipad

.include "../../mk/bsd.pkg.mk"
