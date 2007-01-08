# $NetBSD: Makefile,v 1.3 2007/01/08 18:55:38 adam Exp $

PKGNAME=	postgresql81-plpython-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
