# $NetBSD: Makefile,v 1.15 2013/02/09 11:19:11 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
