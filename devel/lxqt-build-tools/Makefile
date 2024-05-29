# $NetBSD: Makefile,v 1.34 2024/05/29 16:32:15 adam Exp $

DISTNAME=	lxqt-build-tools-0.13.0
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-build-tools/
COMMENT=	LXQt build tools
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++ # Needed to satisfy cmake

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

PKG_SYSCONFSUBDIR=	xdg
CMAKE_ARGS+=		-DLXQT_ETC_XDG_DIR=${PKG_SYSCONFDIR}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

BUILDLINK_API_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.15.0
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
