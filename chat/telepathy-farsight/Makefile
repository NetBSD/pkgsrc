# $NetBSD: Makefile,v 1.25.2.1 2012/10/03 12:06:54 spz Exp $
#

DISTNAME=	telepathy-farsight-0.0.16
PKGREVISION=	11
CATEGORIES=	chat multimedia
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-farsight/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/doc/telepathy-farsight/
COMMENT=	Library for the telepathy part of a voice/video call
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	telepathy-farsight/telepathy-farsight.pc.in

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.12
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../multimedia/farsight2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-python+=	${PYPKGPREFIX}-gstreamer0.10>=0.10.10
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.13.4
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
