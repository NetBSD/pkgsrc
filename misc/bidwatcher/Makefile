# $NetBSD: Makefile,v 1.14 2002/10/12 12:25:55 tron Exp $

DISTNAME=	bidwatcher-1.3.5
CATEGORIES=	misc
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

PATCHFILES=	bidwatcher-1.3.5-p1.diff
PATCH_SITES= 	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
AUTOMAKE_OVERRIDE=	NO

DOCDIR=		${PREFIX}/share/doc/bidwatcher
HTMLDIR=	${PREFIX}/share/doc/html/bidwatcher

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${HTMLDIR}

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
