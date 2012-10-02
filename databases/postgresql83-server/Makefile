# $NetBSD: Makefile,v 1.22 2012/10/02 21:25:42 asau Exp $

PKGNAME=	${DISTNAME:C/-/83-server-/}
COMMENT=	PostgreSQL database server programs

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

.include "../../databases/postgresql83/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl

INSTALL_DIRS=	src/backend
INSTALL_DIRS+=	src/backend/utils/mb/conversion_procs
INSTALL_DIRS+=	src/backend/snowball
INSTALL_DIRS+=	src/timezone
INSTALL_DIRS+=	src/pl
BUILD_DIRS=	src/port
BUILD_DIRS+=	${INSTALL_DIRS}

LIBS.SunOS+=	-lintl

# PostgreSQL has loadable server-side language modules.
#
# Explicitly set DLOPEN_REQUIRE_PTHREADS to "no" on NetBSD as NetBSD-2.x
# had problems with mixing dlopen() and pthreads, which blows up in
# PostgreSQL's backend (pkg/28729).  This works on older and newer
# versions of NetBSD as well since they don't have the bad interaction
# between dlopen() and pthreads.
.if ${OPSYS} == "NetBSD"
DLOPEN_REQUIRE_PTHREADS=	no
.endif
.include "../../mk/dlopen.buildlink3.mk"

# If we're using libltdl to provide "dlopen" functionality, then add the
# dependency and make sure that we link against -lltdl.
.if !empty(USE_LIBLTDL:M[yY][eE][sS])
DL_LIBS+=	-lltdl
.  include "../../devel/libltdl/buildlink3.mk"
.endif

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases
PGUSER?=		pgsql
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGUSER}
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS+=		PGHOME

PKG_GROUPS_VARS+=	PGGROUP
PKG_USERS_VARS+=	PGUSER

PKG_GROUPS=		${PGGROUP}
PKG_USERS=		${PGUSER}:${PGGROUP}
PKG_GECOS.${PGUSER}=	PostgreSQL database administrator
PKG_HOME.${PGUSER}=	${PGHOME}

RCD_SCRIPTS=		pgsql

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# Avoid conflict between "${SSLBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
post-wrapper:
.if ${OPSYS} == "SunOS"
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

.include "../../mk/bsd.pkg.mk"
