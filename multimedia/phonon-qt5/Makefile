# $NetBSD: Makefile,v 1.19 2018/03/24 17:07:53 joerg Exp $

DISTNAME=	phonon-4.9.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
