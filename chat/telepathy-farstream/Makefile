# $NetBSD: Makefile,v 1.2 2017/09/04 18:08:18 wiz Exp $

DISTNAME=	telepathy-farstream-0.6.2
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-farstream/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/doc/telepathy-farstream/
COMMENT=	Farstream connection manager for Telepathy
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	telepathy-farstream/telepathy-farstream.pc.in

.include "../../chat/farstream/buildlink3.mk"
BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.21
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
