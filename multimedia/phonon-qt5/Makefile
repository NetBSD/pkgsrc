# $NetBSD: Makefile,v 1.1 2016/03/01 08:59:54 markd Exp $

DISTNAME=       phonon-4.8.3
PKGNAME=	${DISTNAME:S/-/-qt5-/}

COMMENT=	Multimedia API for KF5

.include "../../multimedia/phonon/Makefile.common"

CMAKE_ARGS+=	-DPHONON_BUILD_PHONON4QT5=ON

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
