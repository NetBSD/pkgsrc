# $NetBSD: Makefile,v 1.32 2003/11/25 08:43:51 tron Exp $

DISTNAME=	bidwatcher-1.3.11-rc1
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

DOCDIR=		${PREFIX}/share/doc/bidwatcher
HTMLDIR=	${PREFIX}/share/doc/html/bidwatcher

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${HTMLDIR}

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
