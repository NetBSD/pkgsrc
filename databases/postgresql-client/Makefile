# $NetBSD: Makefile,v 1.16 2002/10/24 16:25:32 wiz Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
COMMENT=		PostgreSQL database client programs

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--enable-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	cd ${WRKSRC}/src/bin/psql &&					\
		${RM} -f pqsignal.h &&					\
		${LN} -sf ../../interfaces/libpq/pqsignal.h pqsignal.h

post-install:
	cd ${PREFIX}/man && 						\
	${PAX} -crzf ${WRKSRC}/doc/man.tar.gz `${GREP} -v ^# ${FILESDIR}/exclude`

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
