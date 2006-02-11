# $NetBSD: Makefile,v 1.1.1.1 2006/02/11 14:55:51 rxg Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

DBUS_INTERFACE=	python
DBUS_DIRS=	dbus glib python tools

.include "../../sysutils/dbus/Makefile.common"
PKGREVISION=	2

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

# We can't install from within the 'dbus' nor 'tools' directory automatically
# because we'd get a lot of other stuff installed (overriding files in the
# dbus package).
INSTALL_DIRS=	python

PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
