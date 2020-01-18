# $NetBSD: Makefile,v 1.6 2020/01/18 21:49:03 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/96-plpython-/}
PKGREVISION=	1
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql96-server>=${PKGVERSION_NOREV}:../../databases/postgresql96-server

.include "../../databases/postgresql96/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql96-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
