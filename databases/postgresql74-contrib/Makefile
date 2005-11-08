# $NetBSD: Makefile,v 1.8 2005/11/08 16:40:38 joerg Exp $

PKGNAME=		postgresql74-contrib-${BASE_VERS}
PKGREVISION=		# empty
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database contrib programs

.include "../../databases/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/contrib

pre-configure:
	${TOUCH} ${WRKSRC}/src/template/dragonfly
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.c \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.c
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.h
	${CP} ${WRKSRC}/src/backend/port/dynloader/freebsd.h \
		${WRKSRC}/src/backend/port/dynloader/dragonfly.h
	${CP} ${WRKSRC}/src/include/port/freebsd.h \
		${WRKSRC}/src/include/port/dragonfly.h
	${CP} ${WRKSRC}/src/makefiles/Makefile.freebsd \
		${WRKSRC}/src/makefiles/Makefile.dragonfly

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/port && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
