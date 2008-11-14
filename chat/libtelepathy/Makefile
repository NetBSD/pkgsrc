# $NetBSD: Makefile,v 1.1.1.1 2008/11/14 22:58:06 wiz Exp $
#

DISTNAME=	libtelepathy-0.3.3
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/libtelepathy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/
COMMENT=	Unified framework for many different kinds of real-time communications

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	libtelepathy.pc.in

.include "../../chat/telepathy-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.73
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=0.93
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
