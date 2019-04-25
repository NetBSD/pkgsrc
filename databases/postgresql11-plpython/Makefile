# $NetBSD: Makefile,v 1.2 2019/04/25 07:32:41 maya Exp $

PKGNAME=	${DISTNAME:C/-/11-plpython-/}
PKGREVISION=	1
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql11-server>=${PKGVERSION_NOREV}:../../databases/postgresql11-server

.include "../../databases/postgresql11/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql11-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
