# $NetBSD: Makefile,v 1.8 2002/03/22 21:59:55 tron Exp $

DISTNAME=	bidwatcher-1.3.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bidwatcher/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://sourceforge.net/projects/bidwatcher/
COMMENT=        eBay snipe tool

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

DOCDIR=		${PREFIX}/share/doc/bidwatcher
HTMLDIR=	${PREFIX}/share/doc/html/bidwatcher

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for FILE in AUTHORS COPYING INSTALL NEWS README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${DOCDIR}; \
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/quick_start.html ${HTMLDIR}

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
