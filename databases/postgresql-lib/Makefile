# $NetBSD: Makefile,v 1.4 2001/12/03 08:06:26 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-lib-${PG_BASE_VERS}
COMMENT=		PostgreSQL database headers and libraries

USE_BUILDLINK_ONLY=	# defined

DIRS_TO_BUILD=		src/include src/interfaces src/pl

.include "../../mk/bsd.prefs.mk"

do-build:
# Avoid conflict between "/usr/include/crypt.h" and
# "${LOCALBASE}/include/openssl/des.h".
.if (${OPSYS} == "SunOS")
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif
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
