# $NetBSD: Makefile,v 1.188 2022/07/22 17:07:10 micha Exp $

DISTNAME=	rhythmbox-3.4.4
PKGREVISION=	10
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.gnome.org/projects/rhythmbox/
COMMENT=	Music management application for GNOME
LICENSE=	gnu-gpl-v2

.include "options.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_TOOLS+=		itstool
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PYTHON_VERSIONS_INCOMPATIBLE=	27

CONFIGURE_ARGS+=	--disable-browser-plugin
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-fm-radio
CONFIGURE_ARGS+=	--without-gudev
CONFIGURE_ARGS+=	--enable-vala
CONFIGURE_ARGS+=	--with-brasero
CONFIGURE_ARGS+=	--with-ipod

DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
DEPENDS+=	grilo-plugins-[0-9]*:../../net/grilo-plugins
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../lang/python/application.mk"
.include "../../audio/libgpod/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/brasero/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
