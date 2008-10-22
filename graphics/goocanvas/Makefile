# $NetBSD: Makefile,v 1.1.1.1 2008/10/22 10:27:17 obache Exp $
#

DISTNAME=	goocanvas-0.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/goocanvas/0.12/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GooCanvas
COMMENT=	Cairo-based canvas widget for GTK+

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	goocanvas.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
