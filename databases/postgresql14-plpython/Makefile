# $NetBSD: Makefile,v 1.18 2024/05/29 16:31:49 adam Exp $

PKGNAME=	${DISTNAME:S/-/14-plpython-/}
PKGREVISION=	1
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql14-server>=${PKGVERSION_NOREV}:../../databases/postgresql14-server

.include "../../databases/postgresql14/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql14-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
