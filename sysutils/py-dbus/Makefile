# $NetBSD: Makefile,v 1.3 2006/04/02 15:04:20 rxg Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

DBUS_INTERFACE=	glib python
DBUS_DIRS=	dbus bus glib python tools

.include "../../sysutils/dbus/Makefile.common"
DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex
CONFIGURE_ARGS+=--enable-tests
# We can't install from within the 'dbus' nor 'tools' directory automatically
# because we'd get a lot of other stuff installed (overriding files in the
# dbus package).
INSTALL_DIRS=	python

PY_PATCHPLIST=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
