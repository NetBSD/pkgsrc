# $NetBSD: Makefile,v 1.29 2019/08/11 13:22:47 wiz Exp $

PKGNAME=		libpreludedb-python-${VERSION}
PKGREVISION=		18
COMMENT=		Python bindings for LibPreludeDB libraries

.include "../../security/libpreludedb/Makefile.common"

CONFIGURE_ARGS+=	--with-perl=no
CONFIGURE_ARGS+=	--with-mysql=no
CONFIGURE_ARGS+=	--with-postgresql=no
CONFIGURE_ARGS+=	--with-sqlite3=no

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYBINMODULE=		yes
PY_PATCHPLIST=		yes
BUILD_DIRS=		bindings

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.9.24.1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
