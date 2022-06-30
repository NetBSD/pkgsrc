# $NetBSD: Makefile,v 1.77 2022/06/30 11:18:06 nia Exp $

DISTNAME=	swift-4.0.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	https://swift.im/downloads/releases/${DISTNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://swift.im/
COMMENT=	Graphical XMPP Client
LICENSE=	gnu-gpl-v3

# would be nicer to build with pkgsrc version, but
# swift-3.0 does not build with scons>=3
#DEPENDS+=	scons>=1.3:../../devel/scons
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_SED.path+=	-e "s,/usr/local/share/,${PREFIX}/share/,"
SUBST_FILES.path+=	SwifTools/Application/UnixApplicationPathProvider.cpp
SUBST_MESSAGE.path=	Fixing path to support files.

MAKE_ENV+=		qt5=1

CHECK_PORTABILITY_SKIP+=	Swift/Packaging/MacOSX/package.sh

do-configure:
	cd ${WRKSRC} ; \
	${ECHO} "qt=\"${QTDIR}\"" > config.py ;\
	${ECHO} "qt5=1" >> config.py ;\
	${ECHO} "linkflags=\"-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${QTDIR}/lib -Wl,-R${X11BASE}/lib -Wl,-R${BUILDLINK_DIR}/lib ${LDFLAGS}\"" >> config.py ; \
	${ECHO} "ccflags=\"${CXXFLAGS}\"" >> config.py ; \
	${ECHO} "allow_warnings=\"true\"" >> config.py ;

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./scons Swift

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./scons \
	    SWIFT_INSTALLDIR=${DESTDIR}/${PREFIX} ${DESTDIR}/${PREFIX}
	${INSTALL_DATA} ${FILESDIR}/swift-im.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.boost-headers+=   boost-headers>=1.61.0nb1
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
