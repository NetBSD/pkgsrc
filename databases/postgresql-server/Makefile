# $NetBSD: Makefile,v 1.17 2001/12/03 08:06:27 jlam Exp $

.include "../../databases/postgresql/Makefile.common"
.include "../../databases/postgresql/Makefile.ssl"

PKGNAME=		postgresql-server-${PG_BASE_VERS}
COMMENT=		PostgreSQL database server programs

USE_BUILDLINK_ONLY=			# defined
BUILDLINK_DEPENDS.postgresql-lib=	postgresql-lib>=${PG_BASE_VERS}

DEPENDS+=		postgresql-client>=${PG_BASE_VERS}:../../databases/postgresql-client

LIBS+=			${LIBGETOPT}

# mips has no TAS implementation
NOT_FOR_PLATFORM=	*-*-mips

DIRS_TO_BUILD=		src/backend

# PGUSER	username of the database administrator
# PGGROUP	group of the database administrator
# PGHOME	home directory of the database administrator and location of
#		the databases
#
PGUSER?=		pgsql
PGGROUP?=		pgsql
PGHOME?=		${PREFIX}/${PGUSER}
FILES_SUBST+=		PGUSER=${PGUSER}
FILES_SUBST+=		PGHOME=${PGHOME}
BUILD_DEFS=		PGUSER PGROUP PGHOME

PKG_USERS=		${PGUSER}:${PGGROUP}::PostgreSQL\\ database\\ administrator:${PGHOME}:${SH}
PKG_GROUPS=		${PGGROUP}

RCD_SCRIPTS=		pgsql
OWN_DIRS_PERMS=		${PGHOME} ${PGUSER} ${PGGROUP} 0755

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

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

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz		\
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.server`
	${INSTALL_SCRIPT} ${WRKDIR}/pgsql.sh ${PREFIX}/etc/rc.d/pgsql

.include "../../devel/libgetopt/buildlink.mk"
.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
