# $NetBSD: Makefile,v 1.40 2004/10/03 00:12:58 tv Exp $

DISTNAME=	bidwatcher-1.3.16
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_BUILDLINK3=		YES

DOCDIR=		${PREFIX}/share/doc/bidwatcher

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${DOCDIR}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
