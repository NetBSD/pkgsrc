# $NetBSD: Makefile,v 1.10 2016/03/05 11:28:09 jperkin Exp $

DISTNAME=	swift-3.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://swift.im/downloads/releases/${DISTNAME}/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://swift.im/
COMMENT=	Swift XMPP Client
LICENSE=	gnu-gpl-v3

DEPENDS+=	scons>=1.3:../../devel/scons

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_SED.path+=	-e "s,/usr/local/share/,${PREFIX}/share/,"
SUBST_FILES.path+=	SwifTools/Application/UnixApplicationPathProvider.cpp
SUBST_MESSAGE.path=	Fixing path to support files.

MAKE_ENV+=		qt5=1

do-configure:
	cd ${WRKSRC} ; \
	${ECHO} "qt=\"${QTDIR}\"" > config.py ;\
	${ECHO} "qt5=1" >> config.py ;\
	${ECHO} "linkflags=\"-L${PREFIX}/lib -Wl,-R${QTDIR}/lib -Wl,-R${X11BASE}/lib -Wl,-R${BUILDLINK_DIR}/lib\"" >> config.py ; \
	${ECHO} "allow_warnings=\"true\"" >> config.py ;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons Swift

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
	    SWIFT_INSTALLDIR=${DESTDIR}/${PREFIX} ${DESTDIR}/${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/Swift/Packaging/Debian/debian/swift-im.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
