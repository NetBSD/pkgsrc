# $NetBSD: Makefile,v 1.9 2004/10/03 00:12:59 tv Exp $
#

DISTNAME=		kanjipad-2.0.0
PKGREVISION=	1
CATEGORIES=		misc
MASTER_SITES=		http://fishsoup.net/software/kanjipad/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://fishsoup.net/software/kanjipad/
COMMENT=		Japanese handwriting recognition

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kanjipad
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/kanjipad

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
