# $NetBSD: Makefile,v 1.14 2012/09/15 10:04:52 obache Exp $
#

DISTNAME=	gimmage-0.2.3
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/gimmage/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://gimmage.berlios.de/
COMMENT=	GTKMM-based image viewing program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/doc/gimmage
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}/${PREFIX}/share/doc/gimmage/README

.include "../../graphics/cairomm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
