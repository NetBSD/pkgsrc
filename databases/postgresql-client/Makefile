# $NetBSD: Makefile,v 1.6 2001/06/11 02:05:08 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"
.include "../../devel/libgetopt/buildlink.mk"
.include "../../devel/readline/buildlink.mk"

PKGNAME=		postgresql-client-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PostgreSQL database client programs

DEPENDS+=		postgresql-lib>=${PG_BASE_VERS}:../../databases/postgresql-lib

MAKE_ENV+=		INSTALLED_LIBPQ=1
CONFIGURE_ARGS+=	--enable-readline

DIRS_TO_BUILD=		src/bin

# The following is a hack to force ${BUILDLINK_DIR}/lib to the front of the
# linker's library search path without having to patch a lot of Makefile.
# It works because the PostgreSQL Makefiles invoke the linker with $(CFLAGS)
# as well.
#
CFLAGS+=		-L${BUILDLINK_DIR}/lib

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
