# $NetBSD: Makefile,v 1.21 2018/11/14 22:21:32 kleink Exp $

DISTNAME=	libchamplain-0.12.10
PKGNAME=	libchamplain012-0.12.10
PKGREVISION=	19
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libchamplain/0.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/libchamplain
COMMENT=	Map widget
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=--disable-gtk-doc
CONFIGURE_ARGS+=--enable-memphis

PKGCONFIG_OVERRIDE+=	champlain-gtk.pc.in
PKGCONFIG_OVERRIDE+=	champlain.pc.in

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../geography/libmemphis02/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
