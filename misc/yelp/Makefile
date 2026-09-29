# $NetBSD: Makefile,v 1.140 2026/09/29 06:06:43 wiz Exp $

DISTNAME=		yelp-49.2
PKGREVISION=		1
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Mallard capable help browser
LICENSE=		gnu-gpl-v2 AND apache-2.0

USE_TOOLS+=		bash msgfmt pkg-config itstool

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

REPLACE_BASH+=		data/domains/gen_yelp_xml.sh
REPLACE_BASH+=		src/link-gnome-help.sh

PREV_PKGPATH=		misc/yelp

.include "../../devel/meson/build.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.67.4
.include "../../devel/glib2/schemas.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.5
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.yelp-xsl+=	yelp-xsl>=42.3
.include "../../textproc/yelp-xsl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.6.0
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../www/webkit-gtk60/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.16.0
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
