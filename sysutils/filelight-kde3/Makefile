# $NetBSD: Makefile,v 1.3 2012/09/15 10:06:23 obache Exp $
#

DISTNAME=	filelight-1.0
PKGREVISION=	22
CATEGORIES=	sysutils
MASTER_SITES=	http://www.methylblue.com/filelight/packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.methylblue.com/filelight/
COMMENT=	Graphical filesystem usage monitor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
SET_LIBDIR=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

pre-build:
	cd ${WRKSRC}/src/part && env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} dialog.h

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
