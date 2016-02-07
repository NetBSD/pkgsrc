# $NetBSD: Makefile,v 1.95 2016/02/07 14:09:08 adam Exp $

DISTNAME=	fontforge-20150824
CATEGORIES=	fonts editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	fontforge
GITHUB_RELEASE=	20150824

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fontforge.github.io/
COMMENT=	Postscript font editor
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		libfontforge.pc
PKGCONFIG_OVERRIDE+=		libfontforgeexe.pc

CHECK_PORTABILITY_SKIP+=osx/FontForge.app/Contents/MacOS/*
CHECK_INTERPRETER_SKIP+=share/fontforge/python/collab/*
CHECK_INTERPRETER_SKIP+=share/fontforge/python/gdraw/*
CHECK_INTERPRETER_SKIP+=share/fontforge/python/simple/*

PY_PATCHPLIST=		yes

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
