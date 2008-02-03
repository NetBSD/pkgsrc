# $NetBSD: Makefile,v 1.11 2008/02/03 12:22:26 drochner Exp $
#

DISTNAME=	dbus-python-0.82.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	Python bindings for the D-BUS message bus system

USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED=	24
#PYDISTUTILSPKG=			YES
#PYBINMODULE=			YES
PY_PATCHPLIST=			YES

BUILD_DEPENDS+= ${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
# py-libxml2 is only needed at runtime
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
