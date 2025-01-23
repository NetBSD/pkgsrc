# $NetBSD: Makefile,v 1.43 2025/01/23 23:27:29 riastradh Exp $

DISTNAME=	gpgmepp-15.12.2
PKGREVISION=	37
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.2/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://projects.kde.org/gpgmepp
COMMENT=	C++ bindings/wrapper for gpgme
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DKDE_INSTALL_USE_QT_SYS_PATHS=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=5.19.0
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
