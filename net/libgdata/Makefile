# $NetBSD: Makefile,v 1.78 2024/10/10 16:40:46 nia Exp $

DISTNAME=	libgdata-0.18.1
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://live.gnome.org/libgdata
COMMENT=	Google Data API based Glib client library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_TOOLS+=		intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	libgdata.pc.in

# TODO needs gcr and goa packages
#.include "options.mk"
MESON_ARGS+=	-Dgnome=disabled
MESON_ARGS+=	-Dgoa=disabled
MESON_ARGS+=	-Dgtk_doc=true

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.19.7
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# only needed for tests, but checked for by configure
BUILDLINK_DEPMETHOD.uhttpmock?=	build
.include "../../www/uhttpmock/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
