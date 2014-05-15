# $NetBSD: Makefile,v 1.28 2014/05/15 14:41:56 adam Exp $

DISTNAME=	kdenlive-0.9.6
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.kde.org/stable/kdenlive/0.9.6/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor

# INSTALL_UNSTRIPPED=no
# LDFLAGS=-g
# CFLAGS+=-g
# CXXFLAGS+=-g

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt perl pkg-config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
