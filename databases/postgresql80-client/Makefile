# $NetBSD: Makefile,v 1.1.1.1 2005/02/06 12:32:05 jdolecek Exp $

PKGNAME=		postgresql80-client-${BASE_VERS}
PKGREVISION=		# empty
COMMENT=		PostgreSQL database client programs

.include "../../wip/postgresql80/Makefile.common"

# XXX work around core dumps with the native libedit
USE_GNU_READLINE=	yes

CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h

post-install:
	${EGREP} -v "^#" ${FILESDIR}/man.exclude > ${WRKDIR}/man_tar_exclude
	${TAR} -zxm -C ${PG_DIR}/man -X ${WRKDIR}/man_tar_exclude	\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../wip/postgresql80-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
