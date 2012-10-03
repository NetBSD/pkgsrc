# $NetBSD: Makefile,v 1.33 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=	telepathy-glib-0.14.3
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-glib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Telepathy%20GLib
COMMENT=	GObject-based C binding for the Telepathy D-Bus API
LICENSE=	gnu-gpl-v2 AND modified-bsd

BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-vala-bindings
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	telepathy-glib/telepathy-glib.pc.in

PYTHON_FOR_BUILD_ONLY=	yes
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}
REPLACE_PYTHON+=	tests/all-errors-documented.py
TEST_TARGET=		check

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.20.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala014/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.82
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=0.95
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
