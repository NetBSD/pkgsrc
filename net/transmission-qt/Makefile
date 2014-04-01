# $NetBSD: Makefile,v 1.6 2014/04/01 09:48:05 adam Exp $

PKGNAME=	${DISTNAME:C:-:-qt-:}

USE_LANGUAGES=		c c++
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}${PREFIX}

CONFIGURE_ARGS+=	--disable-cli
CONFIGURE_ARGS+=	--disable-daemon
CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

CONFLICTS+=		Transmission-gui-[0-9]*

.include "../../net/transmission/Makefile.common"

post-build:
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake qtr.pro
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} make

do-install:
	cd ${WRKSRC}/qt && ${SETENV} ${INSTALL_ENV} make install

.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
