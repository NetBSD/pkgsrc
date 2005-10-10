# $NetBSD: Makefile,v 1.12 2005/10/10 16:46:02 joerg Exp $

PKGNAME=	postgresql80-server-${BASE_VERS}
PKGREVISION=	2
COMMENT=	PostgreSQL database server programs

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

.include "../../databases/postgresql80/Makefile.common"

# Use shlibtool (invoked as "$(LIBTOOL)") to build modules.
USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
MESSAGE_SRC=		${.CURDIR}/MESSAGE

CONFIGURE_ARGS+=	--with-openssl

BUILD_DIRS=		${WRKSRC}/src/backend
BUILD_DIRS+=		${WRKSRC}/src/backend/utils/mb/conversion_procs
BUILD_DIRS+=		${WRKSRC}/src/timezone
BUILD_DIRS+=		${WRKSRC}/src/pl

# PostgreSQL has loadable server-side language modules.
#
# Explicitly set DLOPEN_REQUIRE_PTHREADS to "no" on NetBSD as NetBSD-2.x
# had problems with mixing dlopen() and pthreads, which blows up in
# PostgreSQL's backend (pkg/28729).  This works on older and newer
# versions of NetBSD as well since they don't have the bad interaction
# between dlopen() and pthreads.
#
.if ${OPSYS} == "NetBSD"
DLOPEN_REQUIRE_PTHREADS=	no
.endif
.include "../../mk/dlopen.buildlink3.mk"

# If we're using libltdl to provide "dlopen" functionality, then add the
# dependency and make sure that we link against -lltdl.
#
.if !empty(USE_LIBLTDL:M[yY][eE][sS])
DL_LIBS+=	-lltdl
.  include "../../devel/libltdl/buildlink3.mk"
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql80-server
PKG_SUPPORTED_OPTIONS=	pam
.include "../../databases/postgresql80/options.mk"

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases
#
PGUSER?=		pgsql
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGUSER}
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS+=		PGUSER PGGROUP PGHOME

PKG_USERS=		${PGUSER}:${PGGROUP}::PostgreSQL\ database\ administrator:${PGHOME}:${SH}
PKG_GROUPS=		${PGGROUP}

RCD_SCRIPTS=		pgsql

.include "../../databases/postgresql80-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# Avoid conflict between "${SSLBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
post-wrapper:
.if ${OPSYS} == "SunOS"
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-build:
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
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC}/src/backend &&					\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}	\
		../../src/include/parser/parse.h			\
		../../src/include/utils/fmgroids.h
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC}/src/port &&					\
       	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
