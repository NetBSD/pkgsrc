# $NetBSD: Makefile,v 1.2 2020/03/08 16:49:15 wiz Exp $

DISTNAME=	lxqt-build-tools-0.6.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-build-tools/0.6.0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://lxqt.org/
COMMENT=	LXQt build tools
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ # Needed to satisfy cmake

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PREFIX}/share/examples/lxqt/xdg

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
