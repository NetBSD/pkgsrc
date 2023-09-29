# $NetBSD: Makefile,v 1.32 2023/09/29 21:12:18 adam Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-odbc-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-odbc
DEPENDS+=	qt6-psql-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-psql
DEPENDS+=	qt6-qt3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qt3d
DEPENDS+=	qt6-qt5compat-${QTVERSION}{,nb[0-9]*}:../../devel/qt6-qt5compat
DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt6-qtbase
DEPENDS+=	qt6-qtcharts-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtcharts
DEPENDS+=	qt6-qtconnectivity-${QTVERSION}{,nb[0-9]*}:../../comms/qt6-qtconnectivity
DEPENDS+=	qt6-qtdatavis3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtdatavis3d
DEPENDS+=	qt6-qtdeclarative-${QTVERSION}{,nb[0-9]*}:../../lang/qt6-qtdeclarative
DEPENDS+=	qt6-qtgrpc-${QTVERSION}{,nb[0-9]*}:../../net/qt6-qtgrpc
DEPENDS+=	qt6-qthttpserver-${QTVERSION}{,nb[0-9]*}:../../www/qt6-qthttpserver
DEPENDS+=	qt6-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtimageformats
DEPENDS+=	qt6-qtlanguageserver-${QTVERSION}{,nb[0-9]*}:../../lang/qt6-qtlanguageserver
DEPENDS+=	qt6-qtlocation-${QTVERSION}{,nb[0-9]*}:../../geography/qt6-qtlocation
DEPENDS+=	qt6-qtlottie-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtlottie
DEPENDS+=	qt6-qtmultimedia-${QTVERSION}{,nb[0-9]*}:../../multimedia/qt6-qtmultimedia
DEPENDS+=	qt6-qtnetworkauth-${QTVERSION}{,nb[0-9]*}:../../security/qt6-qtnetworkauth
DEPENDS+=	qt6-qtpositioning-${QTVERSION}{,nb[0-9]*}:../../geography/qt6-qtpositioning
DEPENDS+=	qt6-qtquick3d-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtquick3d
DEPENDS+=	qt6-qtquicktimeline-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtquicktimeline
DEPENDS+=	qt6-qtremoteobjects-${QTVERSION}{,nb[0-9]*}:../../net/qt6-qtremoteobjects
DEPENDS+=	qt6-qtscxml-${QTVERSION}{,nb[0-9]*}:../../lang/qt6-qtscxml
DEPENDS+=	qt6-qtsensors-${QTVERSION}{,nb[0-9]*}:../../misc/qt6-qtsensors
DEPENDS+=	qt6-qtserialport-${QTVERSION}{,nb[0-9]*}:../../x11/qt6-qtserialport
DEPENDS+=	qt6-qtshadertools-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtshadertools
DEPENDS+=	qt6-qtspeech-${QTVERSION}{,nb[0-9]*}:../../audio/qt6-qtspeech
DEPENDS+=	qt6-qtsvg-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtsvg
DEPENDS+=	qt6-qttools-${QTVERSION}{,nb[0-9]*}:../../devel/qt6-qttools
DEPENDS+=	qt6-qtvirtualkeyboard-${QTVERSION}{,nb[0-9]*}:../../inputmethod/qt6-qtvirtualkeyboard
DEPENDS+=	qt6-qtwebchannel-${QTVERSION}{,nb[0-9]*}:../../www/qt6-qtwebchannel
DEPENDS+=	qt6-qtwebsockets-${QTVERSION}{,nb[0-9]*}:../../net/qt6-qtwebsockets

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND:tl} == yes
DEPENDS+=	qt6-qtwayland-${QTVERSION}{,nb[0-9]*}:../../devel/qt6-qtwayland
.endif

.include "../../mk/bsd.pkg.mk"
