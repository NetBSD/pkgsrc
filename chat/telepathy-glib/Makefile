# $NetBSD: Makefile,v 1.10 2009/04/01 16:20:41 roy Exp $
#

DISTNAME=	telepathy-glib-0.7.26
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-glib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Telepathy%20GLib
COMMENT=	GObject-based C binding for the Telepathy D-Bus API

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	telepathy-glib/telepathy-glib.pc.in

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == "py24" || ${PYPKGPREFIX} == "py23"
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.endif
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.73
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=0.95
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
