# $NetBSD: Makefile,v 1.17 2022/08/11 05:08:07 gutteridge Exp $

DISTNAME=	appstream-glib-0.8.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_TAG=	${DISTNAME:S/-/_/g:S/./_/g}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/appstream-glib/
COMMENT=	GObjects and helper methods for AppStream metadata
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		pkg-config msgfmt xgettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

MESON_ARGS+=		-Drpm=false

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/appstream-glib.pc

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
