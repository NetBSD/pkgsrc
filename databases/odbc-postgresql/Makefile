# $NetBSD: Makefile,v 1.3 2001/05/14 14:52:06 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		odbc-postgresql-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		ODBC interface to PostgreSQL

MAINTAINER=		jwise@netbsd.org

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
