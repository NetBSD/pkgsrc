# $NetBSD: Makefile,v 1.1.1.1 2007/07/17 19:12:02 drochner Exp $
#

DISTNAME=		glade3-3.2.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glade3/3.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://glade.gnome.org/
COMMENT=		User interface builder for the GTK2+ toolkit

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool gmake
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1

PKGCONFIG_OVERRIDE+=	src/glade-3.pc.in
PKGCONFIG_OVERRIDE+=	src/libgladeui-1.0.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
