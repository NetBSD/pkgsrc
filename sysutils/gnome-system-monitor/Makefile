# $NetBSD: Makefile,v 1.7 2008/04/15 18:55:56 drochner Exp $
#

DISTNAME=	gnome-system-monitor-2.22.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-system-monitor/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 system monitor program

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++

CONFLICTS+=		gnome2-system-monitor-[0-9]*

LIBS+=			-lutil
GCONF_SCHEMAS+=	gnome-system-monitor.schemas

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgtop+=	libgtop>=2.19.3

# TODO: Add libgksu support.
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
