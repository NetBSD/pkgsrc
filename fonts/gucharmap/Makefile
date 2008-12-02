# $NetBSD: Makefile,v 1.58 2008/12/02 16:56:58 wiz Exp $
#

DISTNAME=	gucharmap-2.24.2
CATEGORIES=	fonts gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gucharmap/2.24/}
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

BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.6.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.7
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.13.2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
