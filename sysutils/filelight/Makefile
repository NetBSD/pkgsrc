# $NetBSD: Makefile,v 1.12 2008/01/18 05:09:43 tnn Exp $
#

DISTNAME=	filelight-1.0
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.methylblue.com/filelight/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.methylblue.com/filelight/
COMMENT=	Graphical filesystem usage monitor

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

pre-build:
	cd ${WRKSRC}/src/part && env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} dialog.h

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
