# $NetBSD: Makefile,v 1.5 2009/05/19 08:59:17 wiz Exp $
#

DISTNAME=	goocanvas-0.14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/goocanvas/0.14/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GooCanvas
COMMENT=	Cairo-based canvas widget for GTK+
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	goocanvas.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
