# $NetBSD: Makefile,v 1.46 2006/01/24 07:32:03 wiz Exp $
#

DISTNAME=	libbonoboui-2.10.1
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libbonoboui/2.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 Object activation framework library (graphical version)

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	bonobo/libbonoboui-2.0.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

BUILDLINK_DEPENDS.libbonobo+=	libbonobo>=2.10.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
