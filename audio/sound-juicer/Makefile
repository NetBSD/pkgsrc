# $NetBSD: Makefile,v 1.139 2024/05/29 16:31:25 adam Exp $

DISTNAME=	sound-juicer-3.24.0
PKGREVISION=	28
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/sound-juicer/3.24/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/SoundJuicer
COMMENT=	CD ripping tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext itstool
USE_TOOLS+=	gmake

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../audio/libdiscid/buildlink3.mk"
.include "../../audio/libmusicbrainz5/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../sysutils/brasero/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
