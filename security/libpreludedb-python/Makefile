# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 10:04:48 hasso Exp $
#

.include "../../security/libpreludedb/Makefile.common"
.include "../../mk/bsd.prefs.mk"

PATCHDIR=		${.CURDIR}/../libpreludedb/patches
PKGNAME=		libpreludedb-python-${VERSION}
COMMENT=		Python bindings for LibPreludeDB libraries

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYBINMODULE=		yes
PY_PATCHPLIST=		yes
BUILD_DIRS=		bindings

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
