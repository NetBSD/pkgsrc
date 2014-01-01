# $NetBSD: Makefile,v 1.23 2014/01/01 11:52:07 wiz Exp $
#

DISTNAME=	libchamplain-0.8.3
PKGNAME=	libchamplain08-0.8.3
PKGREVISION=	21
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libchamplain/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/libchamplain/
COMMENT=	Map widget
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	champlain-gtk.pc.in
PKGCONFIG_OVERRIDE+=	champlain-memphis.pc.in
PKGCONFIG_OVERRIDE+=	champlain.pc.in

# XXX notyet
#PLIST_VARS+= memphis
#.include "../../geography/memphis/buildlink3.mk"
#PLIST.memphis= yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
