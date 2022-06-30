# $NetBSD: Makefile,v 1.64 2022/06/30 11:18:05 nia Exp $
#

V=		6.0.2
DISTNAME=	kicad-${V}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/code/}
GITLAB_PROJECT=	kicad
GITLAB_RELEASE=	${V}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Schematic and PCB CAD software (stable branch)
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	swig3-[0-9]*:../../devel/swig3
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
USE_TOOLS+=		pkg-config msgfmt msgmerge xgettext

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DKICAD_SPICE=OFF
CMAKE_ARGS+=		-DKICAD_SCRIPTING_WXPYTHON=OFF
CMAKE_ARGS+=		-DKICAD_USE_OCC=OFF # pkgsrc/cad/oce, but it is too old
CMAKE_ARGS+=		-DKICAD_BUILD_I18N=ON

CMAKE_MODULE_PATH_OVERRIDE= \
			new/CMakeLists.txt

PY_PATCHPLIST=		yes

# The package tries to build a native .app bundle. This doesn't work
# in pkgsrc context because they don't support DESTDIR installation,
# which is a requirement in pkgsrc. It also tries to use native Python
# frameworks, but has to use pkgsrc's. Getting this to build requires 15
# additional patches. Ping if you you want the patches.
# I didn't commit them yet because it segfaults. -tnn 20220102
NOT_FOR_PLATFORM+=	Darwin-*-*

# needs 64-bit CAS for std::atomic<size_t>
.include "../../mk/atomic64.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
BUILDLINK_API_DEPENDS.glm+=	glm>=0.9.9.8
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
