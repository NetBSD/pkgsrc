# $NetBSD: Makefile,v 1.2 2026/01/07 08:46:20 wiz Exp $

PKGNAME=	${DISTNAME:S/-/18-plpython-/}
PKGREVISION=	1
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
