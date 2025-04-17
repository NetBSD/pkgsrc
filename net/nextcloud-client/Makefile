# $NetBSD: Makefile,v 1.24 2025/04/17 23:07:10 gdt Exp $
#

DISTNAME=	nextcloud-client-3.16.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nextcloud/}
GITHUB_PROJECT=	desktop
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nextcloud.com/clients
COMMENT=	Nextcloud Desktop Client
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17 filesystem

USE_TOOLS+=		pkg-config
TOOL_DEPENDS+=		qt6-qttools-[0-9]*:../../devel/qt6-qttools

PKG_SYSCONFSUBDIR=	Nextcloud

EGDIR=		${PREFIX}/share/examples/Nextcloud
CONF_FILES=	${EGDIR}/sync-exclude.lst ${PKG_SYSCONFDIR}/sync-exclude.lst

CMAKE_CONFIGURE_ARGS+=	-DSYSCONF_EGDIR:PATH=${EGDIR}
CMAKE_CONFIGURE_ARGS+=	-DSYSCONF_INSTALL_DIR:PATH=${PKG_SYSCONFDIR}

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING:BOOL=OFF

# QtWebEngine is not in pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_WEBENGINE:BOOL=OFF

# force cmake to use rsvg-convert
CMAKE_CONFIGURE_ARGS+=	-DSVG_CONVERTER:FILEPATH=rsvg-convert

# cmake finds these even when we have not depended on them
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PdfLatex:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Sphinx:BOOL=TRUE

AUTO_MKDIRS=	yes

.include "../../devel/cmake/build.mk"

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../devel/kf6-kio/buildlink3.mk"			# optional
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
# In theory, qt6-qttools should be TOOL_DEPENDS only.
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/tool.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../security/libp11/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../x11/kf6-kguiaddons/buildlink3.mk"		# optional
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
