# $NetBSD: Makefile,v 1.95 2020/11/05 09:07:55 ryoon Exp $
#

DISTNAME=	kdevelop-4.7.0
PKGNAME=	kdevelop4-4.7.0
PKGREVISION=	41
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=kdevelop/4.7.0/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	frank@fthieme.net
HOMEPAGE=	https://www.kdevelop.org/
COMMENT=	Integrated Development Environment for Unix/X11/KDE
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config perl msgfmt
USE_LANGUAGES=	c c++

# because of some expansion to ${PKGDIRNAME}.kdev4 which is done wrong by bmake
USE_TOOLS+=	gmake

CMAKE_ARGS+=	-DWITH_KDE4Workspace:BOOL=OFF

#   -std=c++11 is set
GCC_REQD+=	4.7

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/okteta/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/kdevplatform/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
