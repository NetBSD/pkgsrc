# $NetBSD: Makefile,v 1.3 1999/10/24 16:46:27 tron Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.6.0
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.geocities.com/SiliconValley/Haven/5235/

DEPENDS=	imlib-*:../../graphics/imlib

USE_X11BASE=	yes
ALL_TARGET=	gqview

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqview ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
