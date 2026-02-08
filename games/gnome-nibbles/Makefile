# $NetBSD: Makefile,v 1.13 2026/02/08 09:53:38 wiz Exp $

DISTNAME=	gnome-nibbles-4.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-nibbles/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Nibbles
COMMENT=	Guide a worm around a maze
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		itstool pkg-config

.include "../../audio/gsound/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.66.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.5.0
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.14
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
