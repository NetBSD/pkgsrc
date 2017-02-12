# $NetBSD: Makefile,v 1.8 2017/02/12 06:25:48 ryoon Exp $

DISTNAME=	phonon-backend-vlc-0.9.0
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	3

COMMENT=	Multimedia API for KF5 - VLC backend

.include "../../multimedia/phonon-backend-vlc/Makefile.common"

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
