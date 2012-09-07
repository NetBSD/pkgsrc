# $NetBSD: Makefile,v 1.12 2012/09/07 19:16:40 adam Exp $
#

DISTNAME=	libchamplain-0.6.1
PKGNAME=	libchamplain06-0.6.1
PKGREVISION=	11
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libchamplain/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/libchamplain/
COMMENT=	Map widget
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	champlain-gtk.pc.in
PKGCONFIG_OVERRIDE+=	champlain-memphis.pc.in
PKGCONFIG_OVERRIDE+=	champlain.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
