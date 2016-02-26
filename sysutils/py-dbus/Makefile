# $NetBSD: Makefile,v 1.30 2016/02/26 10:24:13 jperkin Exp $

DISTNAME=	dbus-python-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-html-docs --disable-api-docs

PY_PATCHPLIST=			YES

# py-expat is only needed at runtime
DEPENDS+= ${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.6
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
