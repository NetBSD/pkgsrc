# $NetBSD: Makefile,v 1.12 1999/08/29 12:43:34 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp
#

DISTNAME=	gqmpeg-0.6.3
CATEGORIES=	audio
MASTER_SITES=	http://gqview.netpedia.net/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://gqview.netpedia.net/mpeg-over.html

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	mpg123-0.59r:../../audio/mpg123

USE_X11BASE=	yes
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
