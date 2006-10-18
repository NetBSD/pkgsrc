# $NetBSD: Makefile,v 1.14 2006/10/18 19:24:07 adam Exp $

PKGNAME=		postgresql74-contrib-${BASE_VERS}
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database contrib programs

.include "../../databases/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		contrib

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/port && \
	env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
