# $NetBSD: Makefile,v 1.10 2001/12/03 08:06:26 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-client-${PG_BASE_VERS}
COMMENT=		PostgreSQL database client programs

USE_BUILDLINK_ONLY=			# defined
BUILDLINK_DEPENDS.postgresql-lib=	postgresql-lib>=${PG_BASE_VERS}

CONFIGURE_ARGS+=	--enable-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1
LIBS+=			${LIBGETOPT}

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

.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
