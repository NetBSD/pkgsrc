# $NetBSD: Makefile,v 1.51 2026/02/06 10:04:34 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-build-tools-2.3.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-build-tools/
COMMENT=	LXQt build tools
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config perl

PKG_SYSCONFSUBDIR=	xdg
CMAKE_CONFIGURE_ARGS+=	-DLXQT_ETC_XDG_DIR=${PKG_SYSCONFDIR}

BUILDLINK_API_DEPENDS.qt6-qtbase+=	qt6-qtbase>=6.6.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
