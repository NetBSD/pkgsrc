# $NetBSD: Makefile,v 1.104 2026/08/25 10:28:32 adam Exp $

DISTNAME=	xournalpp-1.3.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=xournalpp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xournalpp/xournalpp
COMMENT=	Take notes, sketch and annotate PDFs
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++17 filesystem
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt msgmerge pkg-config xgettext

# downloads files during configure stage
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPPTRACE=OFF
# Always install desktop file for consistent PLIST.
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_DESKTOP_FILES=ON
# Let PkgSrc handle man page compression.
CMAKE_CONFIGURE_ARGS+=	-DMAN_COMPRESS=OFF

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-standalone-[0-9]*:../../print/tex-standalone

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/qpdf/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
