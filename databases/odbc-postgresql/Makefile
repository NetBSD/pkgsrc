# $NetBSD: Makefile,v 1.1.1.1 2001/04/06 21:59:59 jwise Exp $

.include "../../databases/postgresql/Makefile.common"

PKGNAME=		odbc-${DISTNAME}

COMMENT=		ODBC interface to PostgreSQL

DEPENDS+=		postgresql-${PG_VERS}:../../databases/postgresql

MAKE_ENV+=		INSTALLED_LIBPQ=1

CONFIGURE_ARGS+=	--without-perl --without-tcl
CONFIGURE_ARGS+=	--with-odbc --with-odbcinst=/etc

DIRS_TO_BUILD=		interfaces/odbc

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

.include "../../mk/bsd.pkg.mk"
