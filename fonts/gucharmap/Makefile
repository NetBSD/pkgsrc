# $NetBSD: Makefile,v 1.68 2010/06/11 08:50:04 wiz Exp $
#

DISTNAME=	gucharmap-2.28.2
CATEGORIES=	fonts gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gucharmap
COMMENT=	Unicode/ISO10646 character map and font viewer
# unicode-license = BSD style?
#LICENSE=	gnu-gpl-v2 AND unicode-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	gucharmap-2.pc.in

GTK2_IMMODULES=		yes

GCONF_SCHEMAS+=	gucharmap.schemas

# needed for gucharmap-2.28 and gtk2-2.20 -- remove on next update
BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.13.6
.include "../../x11/gtk2/modules.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
