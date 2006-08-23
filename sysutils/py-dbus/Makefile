# $NetBSD: Makefile,v 1.7 2006/08/23 09:45:58 jmmv Exp $
#

DISTNAME=	dbus-python-0.71
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://freedesktop.org/software/dbus/releases/

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_ACCEPTED=	24
PYDISTUTILSPKG=			YES
PYBINMODULE=			YES
PY_PATCHPLIST=			YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
