# $NetBSD: Makefile,v 1.65 2023/01/29 21:17:31 ryoon Exp $

PKGNAME=	transmission-qt-${VERSION}
PKGREVISION=	10
COMMENT=	Free, lightweight BitTorrent client (QT version)

MAKE_ENV+=		QTDIR=${QTDIR}

GCC_REQD+=		7

MAKE_ENV.NetBSD+=	SUBLIBS=-lquota

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}${PREFIX}

CONFIGURE_ARGS+=	--disable-cli
CONFIGURE_ARGS+=	--disable-daemon
CONFIGURE_ARGS+=	--disable-mac
CONFIGURE_ARGS+=	--without-gtk

CONFLICTS+=		Transmission-gui-[0-9]*

INSTALLATION_DIRS=	share/applications

.include "../../net/transmission/Makefile.common"

post-build:
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake qtr.pro
	cd ${WRKSRC}/qt && ${SETENV} ${MAKE_ENV} make

do-install:
	cd ${WRKSRC}/qt && ${SETENV} ${INSTALL_ENV} make install

post-install:
	${INSTALL_DATA} ${FILESDIR}/transmission-qt.desktop		\
	${DESTDIR}${PREFIX}/share/applications/transmission-qt.desktop

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
