# $NetBSD: Makefile,v 1.4 2023/12/23 09:45:05 zafer Exp $

DISTNAME=	dbus-python-1.2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

CONFLICTS+=	py[0-9]*-dbus<1.1.1
CONFLICTS+=	dbus-python-common

USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN}

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.6
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
