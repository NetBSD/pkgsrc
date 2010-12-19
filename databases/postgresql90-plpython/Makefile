# $NetBSD: Makefile,v 1.2 2010/12/19 09:53:29 adam Exp $

PKGNAME=	${DISTNAME:C/-/90-plpython-/}
COMMENT=	PL/Python procedural language for the PostgreSQL backend

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}
CONFIGURE_ARGS+=	--with-python
CONFIGURE_ENV+=		PYTHON="${PYTHONBIN}"

BUILD_DIRS=		src/pl/plpython

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
