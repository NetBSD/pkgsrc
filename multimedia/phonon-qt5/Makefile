# $NetBSD: Makefile,v 1.18 2018/03/12 11:15:40 wiz Exp $

DISTNAME=	phonon-4.9.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	2

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
