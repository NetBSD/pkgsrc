# $NetBSD: Makefile,v 1.1.1.1 2006/12/09 15:34:40 adam Exp $

PKGNAME=	postgresql82-server-${BASE_VERS}
COMMENT=	PostgreSQL database server programs

PKG_DESTDIR_SUPPORT=	user-destdir

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

.include "../../databases/postgresql82/Makefile.common"

# Use shlibtool (invoked as "$(LIBTOOL)") to build modules.
USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

MESSAGE_SRC=		${.CURDIR}/MESSAGE

CONFIGURE_ARGS+=	--with-openssl

BUILD_DIRS=		src/backend
BUILD_DIRS+=		src/backend/utils/mb/conversion_procs
BUILD_DIRS+=		src/timezone
BUILD_DIRS+=		src/pl

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

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql82-server
PKG_SUPPORTED_OPTIONS=	pam
.include "../../databases/postgresql82/options.mk"

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

PKG_GROUPS=		${PGGROUP}
PKG_USERS=		${PGUSER}:${PGGROUP}
PKG_GECOS.${PGUSER}=	PostgreSQL database administrator
PKG_HOME.${PGUSER}=	${PGHOME}
PKG_SHELL.${PGUSER}=	${SH}

RCD_SCRIPTS=		pgsql

.include "../../databases/postgresql82-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# Avoid conflict between "${SSLBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
post-wrapper:
.if ${OPSYS} == "SunOS"
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC}/src/backend &&					\
	env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}	\
		../../src/include/parser/parse.h			\
		../../src/include/utils/fmgroids.h
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC}/src/port &&					\
       	env ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
