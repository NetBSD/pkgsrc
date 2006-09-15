# $NetBSD: Makefile,v 1.42 2006/09/15 15:23:12 jmmv Exp $
#

DISTNAME=	gnome-system-monitor-2.15.92
PKGNAME=	${DISTNAME:S/gnome/gnome2/}
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-system-monitor/2.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 system monitor program

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake intltool msgfmt pkg-config

LIBS+=			-lutil
GCONF2_SCHEMAS+=	gnome-system-monitor.schemas

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize
	cd ${WRKSRC} && autoconf

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0

# TODO: Add libgksu support.
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
