# $NetBSD: Makefile,v 1.42 2011/09/03 15:25:01 obache Exp $
#

DISTNAME=	giflib-4.1.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=giflib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://giflib.sourceforge.net/
COMMENT=	GIF image format library
LICENSE=	mit

CONFLICTS+=	libungif-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

DOCDIR=			${PREFIX}/share/doc/giflib
HTMLDIR=		${PREFIX}/share/doc/html/giflib

REPLACE_PERL+=		util/gifburst

post-patch:
	${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${DESTDIR}${HTMLDIR}
.include "../../mk/bsd.pkg.mk"
