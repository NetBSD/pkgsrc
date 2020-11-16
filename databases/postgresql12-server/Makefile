# $NetBSD: Makefile,v 1.11 2020/11/16 12:15:04 adam Exp $

PKGNAME=	${DISTNAME:S/-/12-server-/}
COMMENT=	PostgreSQL database server programs

# mips has no TAS implementation
BROKEN_ON_PLATFORM=	*-*-mips

.include "../../databases/postgresql12/Makefile.common"

USE_TOOLS+=		msgfmt
TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-openssl

INSTALL_DIRS=	src/backend
INSTALL_DIRS+=	src/backend/replication/libpqwalreceiver
INSTALL_DIRS+=	src/backend/replication/pgoutput
INSTALL_DIRS+=	src/backend/utils/mb/conversion_procs
INSTALL_DIRS+=	src/backend/snowball
INSTALL_DIRS+=	src/timezone
INSTALL_DIRS+=	src/pl
BUILD_DIRS=	src/port
BUILD_DIRS+=	${INSTALL_DIRS}

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
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS+=		PGHOME VARBASE

ALL_ENV+=		INSTALLED_LIBPQ=yes

PKG_GROUPS_VARS+=	PGGROUP
PKG_USERS_VARS+=	PGUSER

PKG_GROUPS=		${PGGROUP}
PKG_USERS=		${PGUSER}:${PGGROUP}
PKG_GECOS.${PGUSER}=	PostgreSQL database administrator
PKG_HOME.${PGUSER}=	${PGHOME}

RCD_SCRIPTS=		pgsql
SMF_METHODS=		postgresql
SMF_NAME=		postgresql

.include "../../databases/postgresql12-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

# Avoid conflict between "${SSLBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
post-wrapper:
.if ${OPSYS} == "SunOS"
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

.include "../../mk/bsd.pkg.mk"
