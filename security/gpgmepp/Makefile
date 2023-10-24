# $NetBSD: Makefile,v 1.33 2023/10/24 22:10:48 wiz Exp $

DISTNAME=	gpgmepp-15.12.2
PKGREVISION=	29
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.2/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://projects.kde.org/gpgmepp
COMMENT=	C++ bindings/wrapper for gpgme
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DKDE_INSTALL_USE_QT_SYS_PATHS=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
