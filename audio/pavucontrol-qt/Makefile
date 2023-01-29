# $NetBSD: Makefile,v 1.28 2023/01/29 21:15:29 ryoon Exp $

DISTNAME=	pavucontrol-qt-1.2.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pavucontrol-qt/
COMMENT=	Pulseaudio mixer implemented in Qt
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.12.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
