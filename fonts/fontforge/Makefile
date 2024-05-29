# $NetBSD: Makefile,v 1.146 2024/05/29 16:32:31 adam Exp $

DISTNAME=	fontforge-20230101
PKGREVISION=	9
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	fontforge
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fontforge.github.io/
COMMENT=	Postscript font editor
LICENSE=	modified-bsd

USE_TOOLS+=	gmake msgfmt pkg-config xgettext
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CMAKE_ARGS+=		-DENABLE_DOCS=NO

PY_PATCHPLIST=		yes

CHECK_PORTABILITY_SKIP+=	osx/FontForge.app/Contents/MacOS/*

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libspiro/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libuninameslist/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
