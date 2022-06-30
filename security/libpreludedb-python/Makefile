# $NetBSD: Makefile,v 1.40 2022/06/30 11:18:47 nia Exp $

PKGNAME=		libpreludedb-python-${VERSION}
PKGREVISION=		28
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

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9.24.1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
