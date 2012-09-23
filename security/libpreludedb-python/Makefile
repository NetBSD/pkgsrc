# $NetBSD: Makefile,v 1.7 2012/09/23 10:47:48 obache Exp $
#

PKGNAME=		libpreludedb-python-${VERSION}
PKGREVISION=		5
COMMENT=		Python bindings for LibPreludeDB libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/libpreludedb/Makefile.common"

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
