# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 14:45:36 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.getopt"
.include "../../databases/postgresql/Makefile.readline"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-client-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PostgreSQL database client programs

DEPENDS+=		postgresql-lib>=${PG_BASE_VERS}:../../databases/postgresql-lib

MAKE_ENV+=		INSTALLED_LIBPQ=1

DIRS_TO_BUILD=		src/bin

pre-configure: link-getopt-headers link-readline-headers

pre-build:
	cd ${WRKSRC}/src/bin/psql &&					\
		${RM} -f pqsignal.h &&					\
		${LN} -sf ../../interfaces/libpq/pqsignal.h pqsignal.h

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor

post-install:
	${SED} -e "s|^#.*||" ${FILESDIR}/exclude			\
		| ${GTAR} zxCXf ${PREFIX}/man - ${WRKSRC}/doc/man.tar.gz

.include "../../mk/bsd.pkg.mk"
