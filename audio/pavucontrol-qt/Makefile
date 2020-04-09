# $NetBSD: Makefile,v 1.1 2020/04/09 00:16:02 gutteridge Exp $

VERSION=	0.14.1
DISTNAME=	pavucontrol-qt-${VERSION}
CATEGORIES=	audio
MASTER_SITES=	https://downloads.lxqt.org/downloads/pavucontrol-qt/${VERSION}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Pulseaudio mixer implemented in Qt
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
