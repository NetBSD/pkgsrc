# $NetBSD: Makefile,v 1.14 2017/09/18 09:53:02 maya Exp $

DISTNAME=	phonon-4.9.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	10

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
