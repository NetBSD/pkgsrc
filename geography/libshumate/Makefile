# $NetBSD: Makefile,v 1.2 2026/08/26 10:19:06 adam Exp $

DISTNAME=	libshumate-1.6.2
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libshumate/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libshumate
COMMENT=	GTK toolkit providing widgets for embedded maps
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.74.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=1.6
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
