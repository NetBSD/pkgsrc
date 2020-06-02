# $NetBSD: Makefile,v 1.65 2020/06/02 08:23:21 adam Exp $

DISTNAME=	telepathy-glib-0.24.1
PKGREVISION=	15
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-glib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/components/telepathy-glib/
COMMENT=	GObject-based C binding for the Telepathy D-Bus API
LICENSE=	gnu-gpl-v2 AND modified-bsd

BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-vala-bindings
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	telepathy-glib/telepathy-glib.pc.in

PYTHON_FOR_BUILD_ONLY=		yes
CONFIGURE_ENV+=			ac_cv_prog_PYTHON=${PYTHONBIN}
REPLACE_PYTHON+=		tests/all-errors-documented.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.24.1
TEST_TARGET=			check

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.36
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.30.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.90
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=0.95
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
