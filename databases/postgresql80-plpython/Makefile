# $NetBSD: Makefile,v 1.2 2005/12/05 20:50:00 rillig Exp $

PKGNAME=	postgresql80-plpython-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql80-server>=${BASE_VERS}:../../databases/postgresql80-server

.include "../../databases/postgresql80/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

BUILD_DIRS=		${WRKSRC}/src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql80-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
