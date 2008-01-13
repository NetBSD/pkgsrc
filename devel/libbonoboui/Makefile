# $NetBSD: Makefile,v 1.62 2008/01/13 05:41:16 minskim Exp $
#

DISTNAME=	libbonoboui-2.20.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libbonoboui/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 Object activation framework library (graphical version)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	bonobo/libbonoboui-2.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.14.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.6.0
BUILDLINK_API_DEPENDS.libbonobo+=	libbonobo>=2.16.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.7

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
