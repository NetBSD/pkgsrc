# $NetBSD: Makefile,v 1.8 2026/02/13 10:52:25 adam Exp $

PKGNAME=	${DISTNAME:S/-/17-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql17-server>=${PKGVERSION_NOREV}:../../databases/postgresql17-server

.include "../../databases/postgresql17/Makefile.common"

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql17-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
