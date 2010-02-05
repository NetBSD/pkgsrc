# $NetBSD: Makefile,v 1.5 2010/02/05 14:50:38 gdt Exp $

PKGNAME=	postgresql84-client-${BASE_VERS}
PKGREVISION=	1
COMMENT=	PostgreSQL database client programs

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/postgresql84/Makefile.common"

# Couldn't find -lpgport, then rebuilt ok.
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gzip tar
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-zlib

# 1. The thread-safety test in ${WRSRC}/src/tools/thread does not pass on
# NetBSD earler than 4.0 or DragonFly.
# 2. configure with --enable-thread-safety fails on OpenBSD.
#
.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-3].*)) || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD"
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

LIBS.SunOS+=	-lintl

INSTALL_DIRS=	src/include
INSTALL_DIRS+=	src/interfaces
INSTALL_DIRS+=	src/bin
INSTALL_DIRS+=	src/port
INSTALL_DIRS+=	doc

BUILD_DIRS=	${INSTALL_DIRS}

# Without this, the Darwin build fails (related to -bundle_loader).
BUILD_DIRS+=	src/backend

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql84-client
.include "../../databases/postgresql84/options.mk"

.for _file_ in pg_service.conf psqlrc
CONF_FILES+=	${PG_DATA_DIR}/${_file_}.sample ${PG_ETC_DIR}/${_file_}
.endfor

# XXX work around core dumps with the native libedit
USE_GNU_READLINE=	yes

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		pgxs
SUBST_STAGE.pgxs=	post-build
SUBST_MESSAGE.pgxs=	Fixing workdir tools references in pgxs Makefile
SUBST_FILES.pgxs=	src/Makefile.global
SUBST_SED.pgxs=		-e 's,${WRKDIR}/.tools,${PREFIX},'
SUBST_SED.pgxs+=	-e 's,${WRKDIR}/.wrapper,${PREFIX},'
SUBST_SED.pgxs+=	-e 's,${WRKSRC},/dev/null,'

INSTALLATION_DIRS+=	${PG_SUBPREFIX}lib/postgresql/pgxs
INSTALLATION_DIRS+=	${PG_SUBPREFIX}lib/postgresql/pgxs/config
INSTALLATION_DIRS+=	${PG_SUBPREFIX}lib/postgresql/pgxs/src
INSTALLATION_DIRS+=	${PG_SUBPREFIX}lib/postgresql/pgxs/src/makefiles

DEST_PG_PGXS=	${DESTDIR}${PG_PREFIX}/lib/postgresql/pgxs
PG_PGXS_FILES=	config/install-sh config/mkinstalldirs
PG_PGXS_FILES+=	src/makefiles/pgxs.mk src/Makefile.global
PG_PGXS_FILES+=	src/Makefile.port src/Makefile.shlib
PG_PGXS_FILES+=	src/nls-global.mk

# On Solaris, avoid conflicts between "${SSLBASE}/include/openssl/des.h"
# and "/usr/include/crypt.h" -- we want the definitions in the former.
.if ${OPSYS} == "SunOS"
post-wrapper:
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

post-install:
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA} $$file ${DESTDIR}${PG_DOC_DIR}/$$file;	\
        done;								\
	for file in ${PG_PGXS_FILES}; do				\
		${INSTALL_DATA} ${WRKSRC}/$$file ${DEST_PG_PGXS}/$$file;\
	done

.include "../../mk/bsd.pkg.mk"
