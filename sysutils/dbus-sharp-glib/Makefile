# $NetBSD: Makefile,v 1.5 2015/04/06 08:17:17 adam Exp $
#

DISTNAME=	dbus-sharp-glib-0.5.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/mono/dbus-sharp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mono/dbus-sharp-glib
COMMENT=	D-Bus for .Net GLib integration module
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	dbus-sharp-glib-1.0.pc.in

.include "../../sysutils/dbus-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
