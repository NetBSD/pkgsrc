# $NetBSD: Makefile,v 1.50 2008/06/20 01:09:25 joerg Exp $

DISTNAME=	bidwatcher-1.3.17
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/bidwatcher/
COMMENT=	eBay snipe tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

DOCDIR=		${PREFIX}/share/doc/bidwatcher
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DESTDIR}${DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${DESTDIR}${DOCDIR}

.include "../../x11/gtk/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
