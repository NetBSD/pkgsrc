# $NetBSD: Makefile,v 1.21 2020/01/18 21:50:09 jperkin Exp $

DISTNAME=	phonon-backend-vlc-0.10.3
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	1

COMMENT=	Multimedia API for KF5 - VLC backend

.include "../../multimedia/phonon-backend-vlc/Makefile.common"

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
