# $NetBSD: Makefile,v 1.17 2018/11/12 03:52:39 ryoon Exp $

DISTNAME=	phonon-backend-vlc-0.10.1
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	2

COMMENT=	Multimedia API for KF5 - VLC backend

.include "../../multimedia/phonon-backend-vlc/Makefile.common"

BUILD_DEPENDS+=	extra-cmake-modules>=5.19.0:../../devel/extra-cmake-modules

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../multimedia/phonon-qt5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
