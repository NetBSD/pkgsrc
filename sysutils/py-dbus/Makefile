# $NetBSD: Makefile,v 1.50 2026/10/13 08:45:54 wiz Exp $

DISTNAME=	dbus_python-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

USE_TOOLS+=		pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

PY_PATCHPLIST=		yes

# in dbus-python-common
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/include/dbus-1.0/dbus/dbus-python.h
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/dbus-python.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.6
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
