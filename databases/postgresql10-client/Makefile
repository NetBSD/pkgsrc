# $NetBSD: Makefile,v 1.27 2022/07/18 22:13:20 tnn Exp $

PKGNAME=	${DISTNAME:S/-/10-client-/}
PKGREVISION=	2
COMMENT=	PostgreSQL database client programs

.include "../../databases/postgresql10/Makefile.common"

USE_TOOLS+=		gzip msgfmt tar
TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-zlib

# Override INSTALL script to avoid unprivileged user/group
# leaking into the binary package
CONFIGURE_ARGS+=	INSTALL=${INSTALL:Q}\ -c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Cygwin"
INSTALLATION_DIRS+=	bin
.endif

# 1. The thread-safety test in ${WRSRC}/src/tools/thread does not pass on
# NetBSD earlier than 4.0 or DragonFly.
# 2. configure with --enable-thread-safety fails on OpenBSD.
.if (${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 040000) || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "MirBSD"
PGSQL_THREAD_SAFETY?=	no
.endif
PGSQL_THREAD_SAFETY?=	yes
BUILD_DEFS+=		PGSQL_THREAD_SAFETY

.if !empty(PGSQL_THREAD_SAFETY:M[yY][eE][sS])
.  include "../../mk/pthread.buildlink3.mk"
.  if (${PTHREAD_TYPE} == "native")
CONFIGURE_ARGS+=	--enable-thread-safety
.  endif
.else
CONFIGURE_ARGS+=	--disable-thread-safety
.endif

BUILD_DIRS+=	src/fe_utils
INSTALL_DIRS=	src/include
INSTALL_DIRS+=	src/common
INSTALL_DIRS+=	src/interfaces
INSTALL_DIRS+=	src/bin
INSTALL_DIRS+=	src/port
BUILD_DIRS+=	${INSTALL_DIRS}
# Without this, the Darwin build fails (related to -bundle_loader).
BUILD_DIRS+=	src/backend

.for f in pg_service.conf psqlrc
CONF_FILES+=	share/postgresql/${f}.sample ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

SUBST_CLASSES+=		pgxs
SUBST_STAGE.pgxs=	post-build
SUBST_MESSAGE.pgxs=	Fixing workdir tools references in pgxs Makefile
SUBST_FILES.pgxs=	src/Makefile.global
SUBST_SED.pgxs=		-e 's,${TOOLS_CMD.bison},${TOOLS_PATH.bison},'
SUBST_SED.pgxs+=	-e 's,${TOOLS_CMD.lex},${TOOLS_PATH.lex},'
SUBST_SED.pgxs+=	-e 's,${TOOLS_CMD.mkdir},${TOOLS_PATH.mkdir},'
SUBST_SED.pgxs+=	-e 's,${WRKDIR}/.wrapper/bin/ld,${LD},'
SUBST_SED.pgxs+=	-e 's,${WRKDIR}/.wrapper,${PREFIX},'
SUBST_SED.pgxs+=	-e 's,${WRKSRC},/dev/null,'

INSTALLATION_DIRS+=	lib/postgresql/pgxs
INSTALLATION_DIRS+=	lib/postgresql/pgxs/config
INSTALLATION_DIRS+=	lib/postgresql/pgxs/src
INSTALLATION_DIRS+=	lib/postgresql/pgxs/src/makefiles

DEST_PGXS=	${DESTDIR}${PREFIX}/lib/postgresql/pgxs
PGXS_FILES=	config/install-sh
PGXS_FILES+=	src/makefiles/pgxs.mk src/Makefile.global
PGXS_FILES+=	src/Makefile.port src/Makefile.shlib
PGXS_FILES+=	src/nls-global.mk

# On Solaris, avoid conflicts between "${SSLBASE}/include/openssl/des.h"
# and "/usr/include/crypt.h" -- we want the definitions in the former.
.if ${OPSYS} == "SunOS"
post-wrapper:
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

post-install:
.for file in ${PGXS_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DEST_PGXS}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
