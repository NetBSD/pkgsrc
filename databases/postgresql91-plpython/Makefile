# $NetBSD: Makefile,v 1.4 2012/07/01 19:49:25 morr Exp $

PKGNAME=	${DISTNAME:C/-/91-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/pl/plpython

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
