# $NetBSD: Makefile,v 1.3 2005/02/07 11:35:42 jlam Exp $

PKGNAME=		postgresql80-server-${BASE_VERS}
PKGREVISION=		# empty
COMMENT=		PostgreSQL database server programs

DEPENDS+=		postgresql80-client>=${BASE_VERS}:../../databases/postgresql80-client

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

.include "../../databases/postgresql80/Makefile.common"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
MESSAGE_SRC=		${.CURDIR}/MESSAGE

CONFIGURE_ARGS+=	--with-openssl
BUILD_DIRS=		${WRKSRC}/src/backend
BUILD_DIRS+=		${WRKSRC}/src/backend/utils/mb/conversion_procs

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql80-server
PKG_SUPPORTED_OPTIONS=	PAM
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MPAM)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

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
BUILD_DEFS=		PGUSER PGGROUP PGHOME

PKG_USERS=		${PGUSER}:${PGGROUP}::PostgreSQL\\ database\\ administrator:${PGHOME}:${SH}
PKG_GROUPS=		${PGGROUP}

RCD_SCRIPTS=		pgsql

post-buildlink:
#
# Avoid conflict between "${LOCALBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if (${OPSYS} == "SunOS")
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/port && \
       	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS}

pre-install:
	@case "X${PGUSER}" in						\
	Xbin|Xetc|Xinclude|Xinfo|Xlib|Xlibdata|Xlibexec|Xman|Xsbin|Xshare) \
		${ECHO} "You have chosen PGUSER=${PGUSER} which will";	\
		${ECHO} "cause trouble, because the postgres home directory"; \
		${ECHO} "would be ${PGHOME}.  Please";			\
		${ECHO} "set PGUSER to something more reasonable";	\
		${ECHO} "like pgsql.";					\
		${ECHO} "";						\
		${FALSE};						\
		;;							\
	esac

post-install:
	${EGREP} -v "^#" ${FILESDIR}/man.server > ${WRKDIR}/man_tar
	cd ${PG_DIR}/man && ${TAR} -zxm -T ${WRKDIR}/man_tar  		\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../databases/postgresql80-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
