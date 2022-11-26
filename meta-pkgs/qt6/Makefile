# $NetBSD: Makefile,v 1.17 2022/11/26 11:27:21 nros Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-odbc-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-odbc
DEPENDS+=	qt6-psql-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-psql
DEPENDS+=	qt6-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtimageformats
DEPENDS+=	qt6-qtshadertools-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtshadertools
DEPENDS+=	qt6-qtsvg-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtsvg
DEPENDS+=	qt6-qtlanguageserver-${QTVERSION}{,nb[0-9]*}:../../lang/qt6-qtlanguageserver
DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt6-qtbase
DEPENDS+=	qt6-qtdeclarative-${QTVERSION}{,nb[0-9]*}:../../lang/qt6-qtdeclarative
DEPENDS+=	qt6-qtwebsockets-${QTVERSION}{,nb[0-9]*}:../../net/qt6-qtwebsockets
DEPENDS+=	qt6-qtcharts-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtcharts
DEPENDS+=	qt6-qtdatavis3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtdatavis3d
DEPENDS+=	qt6-qtlottie-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtlottie
DEPENDS+=	qt6-qtnetworkauth-${QTVERSION}{,nb[0-9]*}:../../security/qt6-qtnetworkauth
DEPENDS+=	qt6-qtquicktimeline-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtquicktimeline
DEPENDS+=	qt6-qtquick3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtquick3d
DEPENDS+=	qt6-qt3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qt3d
DEPENDS+=	qt6-qtremoteobjects-${QTVERSION}{,nb[0-9]*}:../../net/qt6-qtremoteobjects

.include "../../mk/bsd.pkg.mk"
