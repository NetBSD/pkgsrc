# $NetBSD: Makefile,v 1.16 2000/05/25 08:16:50 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp
#

DISTNAME=	gqmpeg-0.6.3
CATEGORIES=	audio
MASTER_SITES=	http://www.netpedia.net/hosting/gqview/packages/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.netpedia.net/hosting/gqview/mpeg-index.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	mpg123-0.59r:../../audio/mpg123

USE_X11BASE=	yes
ALL_TARGET=	gqmpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqmpeg ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
