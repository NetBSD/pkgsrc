# $NetBSD: Makefile,v 1.111 2024/05/29 16:34:22 adam Exp $

DISTNAME=	brasero-3.12.2
PKGREVISION=	24
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/brasero/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Brasero
COMMENT=	CD/DVD burning application
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config perl
USE_TOOLS+=	msgfmt xgettext itstool
USE_TOOLS+=	gmake

TOOL_DEPENDS+=	p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

CONFIGURE_ARGS+=	--disable-nautilus
CONFIGURE_ARGS+=	--enable-compile-warnings=minimum # Disable Werror

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-inotify
.endif

PKGCONFIG_OVERRIDE+=	libbrasero-burn3.pc.in
PKGCONFIG_OVERRIDE+=	libbrasero-media3.pc.in

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
