# $NetBSD: Makefile,v 1.17 2002/10/20 02:41:29 wiz Exp $

DISTNAME=	bidwatcher-1.3.5
CATEGORIES=	misc
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

PATCHFILES=	bidwatcher-1.3.5-p1.diff
PATCH_SITES= 	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
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

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
