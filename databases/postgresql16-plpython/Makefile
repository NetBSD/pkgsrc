# $NetBSD: Makefile,v 1.3 2023/11/08 13:18:34 wiz Exp $

PKGNAME=	${DISTNAME:S/-/16-plpython-/}
PKGREVISION=	2
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql16-server>=${PKGVERSION_NOREV}:../../databases/postgresql16-server

.include "../../databases/postgresql16/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql16-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
