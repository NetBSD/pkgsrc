# $NetBSD: Makefile,v 1.1 2025/10/06 13:30:23 adam Exp $

PKGNAME=	${DISTNAME:S/-/18-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql18-server>=${PKGVERSION_NOREV}:../../databases/postgresql18-server

.include "../../databases/postgresql18/Makefile.common"

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql18-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
