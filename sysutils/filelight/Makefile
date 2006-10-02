# $NetBSD: Makefile,v 1.1.1.1 2006/10/02 18:58:55 rillig Exp $
#

DISTNAME=	filelight-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://methylblue.com/filelight/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://methylblue.com/filelight/packages/
COMMENT=	Graphical filesystem usage monitor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

BUILDLINK_TRANSFORM+=	l:jpeg6b:jpeg

pre-build:
	cd ${WRKSRC}/src/part && env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} dialog.h

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
