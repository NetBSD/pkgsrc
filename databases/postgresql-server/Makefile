# $NetBSD: Makefile,v 1.4 2001/05/18 06:13:54 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"
.include "../../devel/libgetopt/Makefile.getopt"

PKGNAME=		postgresql-server-${PG_VERS}
PG_PKG_VERS=		# empty
COMMENT=		PostgreSQL database server programs

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
.elif ${OPSYS} == "SunOS"
ADDUSER=		useradd
ADDGROUP=		groupadd
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

pre-configure: link-getopt-headers

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

	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		-e "s|@PGUSER@|${PGUSER}|g"				\
		-e "s|@PGHOME@|${PGHOME}|g"				\
		-e "s|@SU@|${SU}|g"					\
		${FILESDIR}/pgsql.sh > ${WRKDIR}/pgsql.sh
	${SED}	-e "s|@PGUSER@|${PGUSER}|g"				\
		-e "s|@PGGROUP@|${PGGROUP}|g"				\
		-e "s|@PGHOME@|${PGHOME}|g"				\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@PGUSER@|${PGUSER}|g"				\
		-e "s|@PGGROUP@|${PGGROUP}|g"				\
		-e "s|@PGHOME@|${PGHOME}|g"				\
		-e "s|@ADDUSER@|${ADDUSER}|g"				\
		-e "s|@ADDGROUP@|${ADDGROUP}|g"				\
		-e "s|@CHGRP@|${CHGRP}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@GREP@|${GREP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@SU@|${SU}|g"					\
		-e "s|@TOUCH@|${TOUCH}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
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

.include "../../mk/bsd.pkg.mk"
