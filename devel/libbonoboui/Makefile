# $NetBSD: Makefile,v 1.117 2018/11/14 22:21:15 kleink Exp $
#

DISTNAME=	libbonoboui-2.24.4
PKGREVISION=	35
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libbonoboui/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME2 Object activation framework library (graphical version)

GNU_CONFIGURE=		yes
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
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# Because pango does not include -lX11, configure does AC_PATH_XTRA
# which links the following three libraries.
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
