# $NetBSD: Makefile,v 1.13 2002/09/14 15:11:31 martin Exp $

DISTNAME=	bidwatcher-1.3.5
CATEGORIES=	misc
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
