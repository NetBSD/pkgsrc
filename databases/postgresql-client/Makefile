# $NetBSD: Makefile,v 1.24 2004/04/27 05:44:22 snj Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
PKGREVISION=		2
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database client programs

USE_BUILDLINK3=		yes

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	cd ${WRKSRC}/src/bin/psql &&					\
	${RM} -f pqsignal.h &&						\
	${LN} -sf ${BUILDLINK_DIR}/include/postgresql/server/libpq/pqsignal.h pqsignal.h
	for file in parser/parse.h utils/fmgroids.h; do			\
		src="${BUILDLINK_DIR}/include/postgresql/server/$$file"; \
		dest="${WRKSRC}/src/include/$$file";			\
		${RM} -f $$dest;					\
		${LN} -sf $$src $$dest;					\
	done

post-install:
	cd ${PREFIX}/man && 						\
		${PAX} -O -crzf ${WRKSRC}/doc/man.tar.gz `${GREP} -v ^# ${FILESDIR}/exclude`

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
