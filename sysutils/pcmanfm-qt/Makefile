# $NetBSD: Makefile,v 1.7 2020/06/01 10:47:53 pin Exp $

VERSION=	0.15.1
DISTNAME=	pcmanfm-qt-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/pcmanfm-qt/releases/download/${VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pcmanfm-qt/
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
