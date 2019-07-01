# $NetBSD: Makefile,v 1.51 2019/07/01 04:08:37 ryoon Exp $

DISTNAME=	kdenlive-0.9.10
PKGREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=kdenlive/0.9.10/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor

# LDFLAGS=-g
# CFLAGS+=-g
# CXXFLAGS+=-g

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt perl pkg-config

CMAKE_ARGS+=	-DWITH_LibV4L2=OFF

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/icons/oxygen/*/mimetypes/application-x-kdenlivetitle.png

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
