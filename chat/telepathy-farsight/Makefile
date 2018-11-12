# $NetBSD: Makefile,v 1.53 2018/11/12 03:51:48 ryoon Exp $

DISTNAME=	telepathy-farsight-0.0.19
PKGREVISION=	6
CATEGORIES=	chat multimedia
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-farsight/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/doc/telepathy-farsight/
COMMENT=	Library for the telepathy part of a voice/video call
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

PKGCONFIG_OVERRIDE+=	telepathy-farsight/telepathy-farsight.pc.in

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gstreamer0.10

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
