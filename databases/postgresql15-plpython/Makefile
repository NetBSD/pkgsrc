# $NetBSD: Makefile,v 1.10 2024/05/29 16:31:50 adam Exp $

PKGNAME=	${DISTNAME:S/-/15-plpython-/}
PKGREVISION=	1
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql15-server>=${PKGVERSION_NOREV}:../../databases/postgresql15-server

.include "../../databases/postgresql15/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql15-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
