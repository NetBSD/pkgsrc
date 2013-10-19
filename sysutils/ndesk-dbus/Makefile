# $NetBSD: Makefile,v 1.15 2013/10/19 09:07:12 adam Exp $

DISTNAME=	ndesk-dbus-0.6.1a
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ndesk.org/DBusSharp
COMMENT=	C\# implementation of dbus

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

DEPENDS+=	dbus>=1.0:../../sysutils/dbus

PKGCONFIG_OVERRIDE+=	ndesk-dbus-1.0.pc.in

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
