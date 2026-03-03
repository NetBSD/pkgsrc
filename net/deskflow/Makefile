# $NetBSD: Makefile,v 1.14 2026/03/03 19:49:24 tnn Exp $

DISTNAME=	deskflow-1.26.0
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=deskflow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deskflow/deskflow/
COMMENT=	Let a user share a mouse and keyboard among computers
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
DEPENDS+=	qt6-qttranslations-[0-9]*:../../x11/qt6-qttranslations

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_USER_DOCS=OFF
# Tests on at least OSX require elevated privileges to interact with for example the clipboard
CMAKE_CONFIGURE_ARGS+=	-DSKIP_BUILD_TESTS=ON

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/lib/common/Settings.h
SUBST_FILES.paths+=	src/lib/deskflow/unix/AppUtilUnix.cpp
SUBST_SED.paths=	-e 's,"/etc,"${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,"/usr/local\(/share/X11/xkb\),"${X11BASE}\1,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CMAKE_INSTALL_PREFIX=	${PREFIX}/Applications
PLIST_SRC=		PLIST.App
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3.0
.include "../../security/openssl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../devel/libportal/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../x11/libei/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
