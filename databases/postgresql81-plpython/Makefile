# $NetBSD: Makefile,v 1.8 2009/03/20 16:02:02 adam Exp $

PKGNAME=	postgresql81-plpython-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql81/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
