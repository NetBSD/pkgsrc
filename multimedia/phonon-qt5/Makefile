# $NetBSD: Makefile,v 1.3 2016/04/11 19:01:36 ryoon Exp $

DISTNAME=       phonon-4.8.3
PKGNAME=	${DISTNAME:S/-/-qt5-/}
PKGREVISION=	2

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
