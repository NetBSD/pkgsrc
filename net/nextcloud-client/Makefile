# $NetBSD: Makefile,v 1.13 2024/09/09 07:52:15 nia Exp $
#

DISTNAME=	nextcloud-client-3.13.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nextcloud/}
GITHUB_PROJECT=	desktop
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nextcloud.com/clients
COMMENT=	Nextcloud Desktop Client
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

USE_CXX_FEATURES+=	filesystem

PKG_SYSCONFSUBDIR=	Nextcloud

EGDIR=		${PREFIX}/share/examples/Nextcloud
CONF_FILES=	${EGDIR}/sync-exclude.lst ${PKG_SYSCONFDIR}/sync-exclude.lst

CMAKE_CONFIGURE_ARGS+=	-DSYSCONF_EGDIR:PATH=${EGDIR}
CMAKE_CONFIGURE_ARGS+=	-DSYSCONF_INSTALL_DIR:PATH=${PKG_SYSCONFDIR}

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING:BOOL=OFF

# used as tool during configure
CMAKE_CONFIGURE_ARGS+=	-DSVG_CONVERTER:FILEPATH=${BUILDLINK_DIR}/bin/rsvg-convert

# cmake finds these even when we have not depended on them
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PdfLatex:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Sphinx:BOOL=TRUE

# ignore warns about xdr functions in a library
LDFLAGS+=	-Wl,--no-fatal-warnings

AUTO_MKDIRS=	yes

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

.include "../../archivers/karchive/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
