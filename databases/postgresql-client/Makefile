# $NetBSD: Makefile,v 1.15 2002/10/24 13:18:05 drochner Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
COMMENT=		PostgreSQL database client programs

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--enable-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

# we need the real GNU tar
BUILD_DEPENDS+=		gtar-base-*:../../archivers/gtar-base
EVAL_PREFIX+=		GTARPREFIX=gtar-base
GTARPREFIX_DEFAULT=	${LOCALBASE}
GTAR=			${GTARPREFIX}/bin/gtar

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
