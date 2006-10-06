# $NetBSD: Makefile,v 1.4 2006/10/06 18:15:10 rillig Exp $
#

DISTNAME=	filelight-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://methylblue.com/filelight/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://methylblue.com/filelight/
COMMENT=	Graphical filesystem usage monitor

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

pre-build:
	cd ${WRKSRC}/src/part && env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} dialog.h

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
