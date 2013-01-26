# $NetBSD: Makefile,v 1.12 2013/01/26 21:36:48 adam Exp $

DISTNAME=	ndesk-dbus-glib-0.4.1
PKGREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ndesk.org/DBusSharp
COMMENT=	C\# implementation of dbus - GLib integration

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	ndesk-dbus-glib-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
