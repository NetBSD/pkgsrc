# $NetBSD: Makefile,v 1.4 2009/03/20 16:02:41 adam Exp $

PKGNAME=	postgresql83-plpython-${BASE_VERS}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql83-server>=${BASE_VERS}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
