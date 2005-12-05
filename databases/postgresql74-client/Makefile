# $NetBSD: Makefile,v 1.18 2005/12/05 23:55:05 rillig Exp $

PKGNAME=		postgresql74-client-${BASE_VERS}
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database client programs

.include "../../databases/postgresql74/Makefile.common"

# XXX work around core dumps with the native libedit
USE_GNU_READLINE=	yes

USE_TOOLS+=		tar
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h

post-install:
	${EGREP} -v "^#" ${FILESDIR}/man.client > ${WRKDIR}/man_tar_files
	cd ${PREFIX}/man && ${TAR} -zxm -T ${WRKDIR}/man_tar_files	\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
