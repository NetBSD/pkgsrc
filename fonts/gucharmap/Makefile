# $NetBSD: Makefile,v 1.60 2009/03/15 19:42:26 jmcneill Exp $
#

DISTNAME=	gucharmap-2.26.0
CATEGORIES=	fonts gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Gucharmap
COMMENT=	Unicode/ISO10646 character map and font viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	gucharmap-2.pc.in

GTK2_IMMODULES=		yes

GCONF_SCHEMAS+=	gucharmap.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.3
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.13.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
