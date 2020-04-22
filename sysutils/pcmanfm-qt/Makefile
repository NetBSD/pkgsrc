# $NetBSD: Makefile,v 1.5 2020/04/22 08:33:48 pin Exp $

DISTNAME=	pcmanfm-qt-0.14.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.lxqt.org/downloads/pcmanfm-qt/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	LXQt pcmanfm Qt frontend
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	lxmenu-data-[0-9]*:../../sysutils/lxmenu-data

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
