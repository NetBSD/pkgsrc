# $NetBSD: Makefile,v 1.9 2007/09/03 10:00:34 drochner Exp $
#

DISTNAME=	dbus-python-0.82.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED=	24
#PYDISTUTILSPKG=			YES
#PYBINMODULE=			YES
PY_PATCHPLIST=			YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
# py-libxml2 is only needed at runtime
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
