# $NetBSD: Makefile,v 1.14 2002/10/19 03:03:50 jlam Exp $

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
	${SED} -e "s|^#.*||" ${FILESDIR}/exclude			\
		| ${GTAR} zxCXf ${PREFIX}/man - ${WRKSRC}/doc/man.tar.gz

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
