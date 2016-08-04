# $NetBSD: Makefile,v 1.5 2016/08/04 17:03:37 ryoon Exp $

DISTNAME=       phonon-4.9.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	1

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
