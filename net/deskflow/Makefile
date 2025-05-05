# $NetBSD: Makefile,v 1.1 2025/05/05 08:39:56 tnn Exp $

DISTNAME=	deskflow-1.21.2
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=deskflow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deskflow/deskflow/
COMMENT=	Let a user share a mouse and keyboard among computers
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20
USE_TOOLS+=		pkg-config

DISTFILES=		${DEFAULT_DISTFILES}

CLI11_VERSION=		2.4.2
DISTFILES+=		CLI11-${CLI11_VERSION}.hpp
SITES.CLI11-${CLI11_VERSION}.hpp=	\
			-https://github.com/CLIUtils/CLI11/releases/download/v${CLI11_VERSION}/CLI11.hpp

TOMLPP_VERSION=		3.4.0
DISTFILES+=		toml-${TOMLPP_VERSION}.hpp
SITES.toml-${TOMLPP_VERSION}.hpp=	\
			-https://raw.githubusercontent.com/marzer/tomlplusplus/refs/tags/v${TOMLPP_VERSION}/toml.hpp

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/lib/common/Settings.h
SUBST_SED.paths=	-e 's,"/etc,"${PKG_SYSCONFDIR},g'

post-extract:
	${MKDIR} -p ${WRKSRC}/${CMAKE_BUILD_DIR}/include/CLI
	${MV} ${WRKDIR}/CLI11-${CLI11_VERSION}.hpp ${WRKSRC}/${CMAKE_BUILD_DIR}/include/CLI/CLI.hpp
	${MKDIR} -p ${WRKSRC}/${CMAKE_BUILD_DIR}/include/toml++
	${MV} ${WRKDIR}/toml-${TOMLPP_VERSION}.hpp ${WRKSRC}/${CMAKE_BUILD_DIR}/include/toml++/toml.h

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CMAKE_INSTALL_PREFIX=	${PREFIX}/Applications
PLIST_SRC=		PLIST.App
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
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
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
