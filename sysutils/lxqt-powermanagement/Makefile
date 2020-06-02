# $NetBSD: Makefile,v 1.4 2020/06/02 10:30:45 pin Exp $

DISTNAME=	lxqt-powermanagement-0.15.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-powermanagement/
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
