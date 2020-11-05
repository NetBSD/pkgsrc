# $NetBSD: Makefile,v 1.30 2020/11/05 09:08:16 ryoon Exp $

DISTNAME=	geoclue-2.5.6
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	https://gitlab.freedesktop.org/geoclue/geoclue/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/geoclue/geoclue/-/wikis/home
COMMENT=	Geoinformation service API and base providers
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-D3g-source=false
MESON_ARGS+=	-Dcdma-source=false
MESON_ARGS+=	-Dnmea-source=false
MESON_ARGS+=	-Dmodem-gps-source=false
MESON_ARGS+=	-Ddemo-agent=false

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/geoclue-2.0.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/libgeoclue-2.0.pc

CONF_FILES+=	share/examples/dbus-1/system.d/org.freedesktop.GeoClue2.Agent.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.GeoClue2.Agent.conf
CONF_FILES+=	share/examples/dbus-1/system.d/org.freedesktop.GeoClue2.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.GeoClue2.conf
CONF_FILES+=	share/examples/geoclue/geoclue.conf \
		${PKG_SYSCONFDIR}/geoclue.conf

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
