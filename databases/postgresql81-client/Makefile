# $NetBSD: Makefile,v 1.3.6.1 2006/10/31 10:18:20 ghen Exp $

PKGNAME=	postgresql81-client-${BASE_VERS}
COMMENT=	PostgreSQL database client programs

.include "../../databases/postgresql81/Makefile.common"

USE_TOOLS+=		gzip tar
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-zlib

CONFLICTS+=	postgresql81-lib-*
CONFLICTS+=	postgresql81-docs-*

# 1. The thread-safety test in ${WRSRC}/src/tools/thread does not pass on
# NetBSD (missing strerror_r) or DragonFly.
# 2. configure with --enable-thread-safety fails on OpenBSD.
#
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD"
PGSQL_THREAD_SAFETY?=	no
.endif
PGSQL_THREAD_SAFETY?=	yes
BUILD_DEFS+=		PGSQL_THREAD_SAFETY

.if !empty(PGSQL_THREAD_SAFETY:M[yY][eE][sS])
.  include "../../mk/pthread.buildlink3.mk"
.  if (${PTHREAD_TYPE} == "native")
CONFIGURE_ARGS+=	--enable-thread-safety
.  endif
.endif

INSTALL_DIRS=	${WRKSRC}/src/include
INSTALL_DIRS+=	${WRKSRC}/src/interfaces
INSTALL_DIRS+=	${WRKSRC}/src/bin
INSTALL_DIRS+=	${WRKSRC}/doc

BUILD_DIRS=	${INSTALL_DIRS}

# Without this, the Darwin build fails (related to -bundle_loader).
BUILD_DIRS+=	${WRKSRC}/src/backend

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql81-client
.include "../../databases/postgresql81/options.mk"

.for _file_ in pg_service.conf psqlrc
CONF_FILES+=	${PG_DATA_DIR}/${_file_}.sample ${PG_ETC_DIR}/${_file_}
.endfor
.if !empty(PG_SUBPREFIX)
PLIST_SUBST+=	PG_DIRRM_SUBPREFIX="@dirrm ${PG_SUBPREFIX}"
.else
PLIST_SUBST+=	PG_DIRRM_SUBPREFIX="@comment empty line"
.endif

# XXX work around core dumps with the native libedit
USE_GNU_READLINE=	yes

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# On Solaris, avoid conflicts between "${SSLBASE}/include/openssl/des.h"
# and "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if ${OPSYS} == "SunOS"
post-wrapper:
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC}/src/backend &&					\
	env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}	\
		../../src/include/parser/parse.h			\
		../../src/include/utils/fmgroids.h

post-install:
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA} $$file ${PG_DOC_DIR}/$$file;		\
        done
	cp -R ${WRKSRC}/doc/TODO.detail ${PG_DOC_DIR}
	chown -R ${DOCOWN}:${DOCGRP} ${PG_DOC_DIR}/TODO.detail

.include "../../mk/bsd.pkg.mk"
