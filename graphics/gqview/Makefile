# $NetBSD: Makefile,v 1.4 1999/12/20 18:20:02 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.7.0
CATEGORIES=	graphics x11
MASTER_SITES=	http://gqview.netpedia.net/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://gqview.netpedia.net/view-over.html

DEPENDS=	imlib-*:../../graphics/imlib

USE_X11BASE=	yes
ALL_TARGET=	gqview

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqview ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
