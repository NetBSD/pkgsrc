# $NetBSD: Makefile,v 1.12.2.2 2002/06/21 23:05:03 jlam Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
COMMENT=		PostgreSQL database client programs

USE_BUILDLINK2=		YES

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

DIRS_TO_BUILD=		src/bin

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

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
