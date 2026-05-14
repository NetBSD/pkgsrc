# $NetBSD: Makefile,v 1.47 2026/05/14 16:42:01 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-sudo-2.4.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-sudo/
COMMENT=	LXQt GUI frontend for sudo
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

CMAKE_CONFIGURE_ARGS+=	-DMSK_INSTALL_INCLUDES=/include

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
