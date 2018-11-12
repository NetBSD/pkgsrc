# $NetBSD: Makefile,v 1.25 2018/11/12 03:51:20 ryoon Exp $

DISTNAME=	phonon-4.10.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

BUILDLINK_ABI_DEPENDS.qt5-qtbase+=	qt5-qtbase>=5.10.1nb2
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
