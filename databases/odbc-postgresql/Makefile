# $NetBSD: Makefile,v 1.4 2001/05/23 07:19:12 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		odbc-postgresql-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		ODBC interface to PostgreSQL

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://odbc.postgresql.org/

CONFIGURE_ARGS+=	--with-odbc
CONFIGURE_ARGS+=	--with-odbcinst=/etc

DIRS_TO_BUILD=		src/interfaces/odbc

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
.endfor

.include "../../mk/bsd.pkg.mk"
