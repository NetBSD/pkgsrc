# $NetBSD: Makefile,v 1.36 2004/04/24 18:04:06 snj Exp $

DISTNAME=	bidwatcher-1.3.13
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_BUILDLINK3=		YES

DOCDIR=		${PREFIX}/share/doc/bidwatcher
HTMLDIR=	${PREFIX}/share/doc/html/bidwatcher

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${HTMLDIR}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
