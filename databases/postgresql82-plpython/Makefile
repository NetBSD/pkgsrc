# $NetBSD: Makefile,v 1.9 2010/02/10 19:17:34 joerg Exp $

PKGNAME=	postgresql82-plpython-${BASE_VERS}
PKGREVISION=	2
COMMENT=	PL/Python procedural language for the PostgreSQL backend

DEPENDS+=	postgresql82-server>=${BASE_VERS}:../../databases/postgresql82-server

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql82/Makefile.common"

CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql82-client/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
