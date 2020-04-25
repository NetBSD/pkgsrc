# $NetBSD: Makefile,v 1.1 2020/04/25 17:15:57 gutteridge Exp $

DISTNAME=	lxqt-powermanagement-0.14.1
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-powermanagement/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Daemon used for power management and auto-suspend
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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
