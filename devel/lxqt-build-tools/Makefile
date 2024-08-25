# $NetBSD: Makefile,v 1.37 2024/08/25 06:18:36 wiz Exp $

DISTNAME=	lxqt-build-tools-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-build-tools/
COMMENT=	LXQt build tools
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++ # Needed to satisfy cmake

PKG_SYSCONFSUBDIR=	xdg
CMAKE_CONFIGURE_ARGS+=		-DLXQT_ETC_XDG_DIR=${PKG_SYSCONFDIR}

BUILDLINK_API_DEPENDS.qt6-qtbase+=	qt6-qtbase>=6.6.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
