# $NetBSD: Makefile,v 1.44 2023/10/23 06:37:52 wiz Exp $

DISTNAME=	dbus-python-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system
LICENSE=	mit

USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	PYTHON=${PYTHONBIN}

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_TRANSFORM.SunOS+=	rm:-std=c9x

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.6
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-python-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
