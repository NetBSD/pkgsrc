# $NetBSD: Makefile,v 1.114 2020/06/05 12:49:05 jperkin Exp $

DISTNAME=	fontforge-20190801
PKGREVISION=	4
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	fontforge
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fontforge.github.io/
COMMENT=	Postscript font editor
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar

USE_TOOLS+=	gmake msgfmt pkg-config xgettext
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

# C++11
GCC_REQD+=	4.8

# Make the build reproducable.
CONFIGURE_ENV+=		SOURCE_DATE_EPOCH=${PKGVERSION_NOREV}0000

CONFIGURE_ARGS+=	--enable-gdk
CONFIGURE_ARGS+=	--enable-woff2

USE_PKGLOCALEDIR=	yes
PY_PATCHPLIST=		yes

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		libfontforge.pc
PKGCONFIG_OVERRIDE+=		libfontforgeexe.pc

CHECK_PORTABILITY_SKIP+=	osx/FontForge.app/Contents/MacOS/*
CHECK_INTERPRETER_SKIP+=	share/fontforge/python/collab/*
CHECK_INTERPRETER_SKIP+=	share/fontforge/python/gdraw/*
CHECK_INTERPRETER_SKIP+=	share/fontforge/python/simple/*

.include "../../mk/bsd.prefs.mk"

# Requires GNU date features
.if ${OPSYS} == "SunOS"
_TOOLS_USE_PKGSRC.date=	yes
.endif

.include "../../lang/python/application.mk"
# Python38 needs use of pkgconfig python-3.8-embed
.if ${PYPKGPREFIX} == "py38"
EMBED=-embed
.else
EMBED=
.endif
SUBST_CLASSES+=		pkgconf
SUBST_STAGE.pkgconf=	pre-configure
SUBST_FILES.pkgconf=	configure
SUBST_VARS.pkgconf=	EMBED

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
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
.include "../../mk/bsd.pkg.mk"
