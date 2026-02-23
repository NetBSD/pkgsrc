# $NetBSD: Makefile,v 1.4 2026/02/23 07:15:44 wiz Exp $

DISTNAME=	kdsoap-ws-discovery-client-0.4.0
PKGREVISION=	2
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_KDE:=kdsoap-ws-discovery-client/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://caspermeijn.gitlab.io/kdsoap-ws-discovery-client/
COMMENT=	WS-Discovery client library based on KDSoap
LICENSE=	cc0-1.0-universal AND gnu-gpl-v3

USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DQT_MAJOR_VERSION=6
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../net/kdsoap/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
