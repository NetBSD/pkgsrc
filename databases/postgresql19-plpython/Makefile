# $NetBSD: Makefile,v 1.1 2026/11/24 19:22:52 adam Exp $

PKGNAME=	${DISTNAME:S/-/19-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql19-server>=${PKGVERSION_NOREV}:../../databases/postgresql19-server

.include "../../databases/postgresql19/Makefile.common"

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql19-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
