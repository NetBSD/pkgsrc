# $NetBSD: Makefile,v 1.35 2020/11/05 09:07:08 ryoon Exp $

DISTNAME=	ndesk-dbus-glib-0.4.1
PKGREVISION=	30
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ndesk.org/DBusSharp
COMMENT=	C\# implementation of dbus - GLib integration

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	ndesk-dbus-glib-1.0.pc.in

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
