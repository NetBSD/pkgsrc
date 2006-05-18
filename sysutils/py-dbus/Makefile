# $NetBSD: Makefile,v 1.5 2006/05/18 20:30:01 wiz Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

BROKEN_IN=	pkgsrc-2006Q1

PYTHON_VERSIONS_ACCEPTED= 24

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
