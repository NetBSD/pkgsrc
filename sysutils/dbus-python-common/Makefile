# $NetBSD: Makefile,v 1.39 2026/10/13 08:50:22 wiz Exp $

DISTNAME=	dbus_python-1.5.0
PKGNAME=	${DISTNAME:S/python/python-common/:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

CONFLICTS+=	py[0-9]*-dbus<1.1.1

USE_TOOLS+=	pkg-config
MESON_ARGS+=	-Ddoc=disabled
MESON_INSTALL=	no

PYTHON_FOR_BUILD_ONLY=	yes

INSTALLATION_DIRS+=	include/dbus-1.0/dbus
INSTALLATION_DIRS+=	lib/pkgconfig

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/dbus/dbus-python.h \
		${DESTDIR}${PREFIX}/include/dbus-1.0/dbus
	${INSTALL_DATA} ${WRKSRC}/output/meson-private/dbus-python.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
