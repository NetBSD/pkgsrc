# $NetBSD: Makefile,v 1.16 2013/09/02 19:50:41 adam Exp $
#

DISTNAME=	libpeas-1.6.2
PKGREVISION=	5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libpeas/1.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libpeas
COMMENT=	GObject-based plugins engine
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

PKGCONFIG_OVERRIDE+=	data/libpeas-gtk-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/libpeas-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
