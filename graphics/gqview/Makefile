# $NetBSD: Makefile,v 1.2 1999/08/28 09:43:10 rh Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.6.0
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Haven/5235/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.geocities.com/SiliconValley/Haven/5235/

DEPENDS=	gtk+-1.2.4:../../x11/gtk \
		imlib-1.9.4:../../graphics/imlib

USE_X11BASE=	yes
ALL_TARGET=	gqview

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gqview ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
