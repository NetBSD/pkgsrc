# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 14:47:30 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-lib-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PostgreSQL database headers and libraries

DIRS_TO_BUILD=		src/include src/interfaces src/pl

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
	cd ${WRKSRC}/src/include && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} install-all-headers

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz             \
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.lib`

.include "../../mk/bsd.pkg.mk"
