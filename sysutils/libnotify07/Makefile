# $NetBSD: Makefile,v 1.3 2013/04/22 11:58:14 rodent Exp $

DISTNAME=	libnotify-0.7.5
PKGNAME=	${DISTNAME:S/-/07-/1}
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libnotify/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/libnotify/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	libnotify-[0-9]*

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "options.mk"

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_DEPMETHOD.gdk-pixbuf2?=	build
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
