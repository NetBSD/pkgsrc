# $NetBSD: Makefile,v 1.18 2013/02/09 11:19:09 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython
BUILD_MAKE_FLAGS=	PGXS=1

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
