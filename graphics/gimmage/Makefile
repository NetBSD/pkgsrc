# $NetBSD: Makefile,v 1.49 2019/07/01 04:08:20 ryoon Exp $
#

DISTNAME=	gimmage-0.2.3
PKGREVISION=	42
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/gimmage/

MAINTAINER=	reed@reedmedia.net
#HOMEPAGE=	http://gimmage.berlios.de/
COMMENT=	GTKMM-based image viewing program

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	share/doc/gimmage
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}/${PREFIX}/share/doc/gimmage/README

.include "../../graphics/cairomm/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
