# $NetBSD: Makefile,v 1.12 2005/05/22 20:08:15 jlam Exp $
#

DISTNAME=		kanjipad-2.0.0
PKGREVISION=	1
CATEGORIES=		misc
MASTER_SITES=		http://fishsoup.net/software/kanjipad/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_TOOLS+=		gmake
USE_PERL5=		build

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjipad
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kanjipad

.include "../../mk/bsd.pkg.mk"
