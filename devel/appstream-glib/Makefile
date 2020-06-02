# $NetBSD: Makefile,v 1.4 2020/06/02 08:23:33 adam Exp $

DISTNAME=	appstream-glib-appstream_glib_0_7_17
PKGNAME=	appstream-glib-0.7.17
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_PROJECT=	appstream-glib
GITHUB_TAG=	appstream_glib_0_7_17

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/appstream-glib/
COMMENT=	GObjects and helper methods for AppStream metadata
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

MESON_ARGS+=		-Drpm=false

PKGCONFIG_OVERRIDE+=	libappstream-glib/appstream-glib.pc.in

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libstemmer/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
