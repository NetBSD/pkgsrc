# $NetBSD: Makefile,v 1.11 2001/08/14 03:41:38 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-server-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PostgreSQL database server programs

USE_BUILDLINK_ONLY=			# defined
BUILDLINK_DEPENDS.postgresql-lib=	postgresql-lib>=${PG_BASE_VERS}

DEPENDS+=		postgresql-client>=${PG_BASE_VERS}:../../databases/postgresql-client

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

DIRS_TO_BUILD=		src/backend

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases

PGUSER?=		pgsql
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGUSER}
BUILD_DEFS=		PGUSER PGROUP PGHOME

.if ${OPSYS} == "NetBSD"
.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif
.else
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		PREFIX=${PREFIX}
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGGROUP=${PGGROUP}
FILES_SUBST+=		PGHOME=${PGHOME}

FILES_SUBST+=		ADDUSER=${ADDUSER:Q}
FILES_SUBST+=		ADDGROUP=${ADDGROUP:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		ID=${ID:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		SU=${SU:Q}
FILES_SUBST+=		TOUCH=${TOUCH:Q}

FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-build:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}
.endfor

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

	${SED} ${FILES_SUBST_SED} ${FILESDIR}/pgsql.sh > ${WRKDIR}/pgsql.sh
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.server`
	${INSTALL_SCRIPT} ${WRKDIR}/pgsql.sh ${PREFIX}/etc/rc.d/pgsql
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/libgetopt/buildlink.mk"
.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
