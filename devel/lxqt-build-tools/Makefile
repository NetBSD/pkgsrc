# $NetBSD: Makefile,v 1.7 2020/06/02 08:23:39 adam Exp $

VERSION=	0.7.0
DISTNAME=	lxqt-build-tools-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/lxqt-build-tools/releases/download/${VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-build-tools/
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
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
