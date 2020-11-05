# $NetBSD: Makefile,v 1.2 2020/11/05 09:07:46 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/13-plpython-/}
PKGREVISION=	1
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql13-server>=${PKGVERSION_NOREV}:../../databases/postgresql13-server

.include "../../databases/postgresql13/Makefile.common"

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython contrib/hstore_plpython

.include "../../databases/postgresql13-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
