# $NetBSD: Makefile,v 1.13 2022/06/30 11:18:49 nia Exp $

CONFLICTS=		bareos-clientonly-[0-9]* bacula-clientonly-[0-9]* bacula-[0-9]*

COMMENT=		Backup Archiving REcovery Open Sourced
PKGREVISION=		4

RCD_SCRIPTS=		bareos bareos-dir bareos-sd bareos-fd

# For make_catalog_backup.pl.in.
USE_TOOLS+=		perl:run
# strange: pkglint complains about VARBASE not defined in BUILD_DEFS, but it is defined in Makefile.common
BUILD_DEFS+=		VARBASE

BAREOS_SD_USER?=		bareossd
PKG_GECOS.${BAREOS_SD_USER}=	Bareos Storage User
PKG_HOME.${BAREOS_SD_USER}=	${BAREOS_WORKINGDIR}
PKG_SHELL.${BAREOS_SD_USER}=	/bin/sh

BAREOS_DIR_USER?=		bareosdir
PKG_GECOS.${BAREOS_DIR_USER}=	Bareos Director User
PKG_HOME.${BAREOS_DIR_USER}=	${BAREOS_WORKINGDIR}
PKG_SHELL.${BAREOS_DIR_USER}=	/bin/sh

PKG_USERS=		${BAREOS_DIR_USER}:${BAREOS_GROUP} ${BAREOS_SD_USER}:${BAREOS_GROUP}

.include "options.mk"
.include "Makefile.common"

# needs to be here to get ${EGREP} defined
.include "../../mk/bsd.pkg.mk"

DIR_PERMS.bareos-dir.d=	${BAREOS_DIR_USER} ${BAREOS_GROUP} 0770
DIR_PERMS.bareos-sd.d=	${BAREOS_SD_USER} ${BAREOS_GROUP} 0770
DIR_PERMS.bareos-fd.d=	${REAL_ROOT_USER} ${BAREOS_GROUP} 0770
DIR_PERMS=		${REAL_ROOT_USER} ${BAREOS_GROUP} 0775

# spool directory
MAKE_DIRS_PERMS?=
MAKE_DIRS_PERMS+=	${VARBASE}/${PKG_SYSCONFSUBDIR} \
			${REAL_ROOT_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/working \
			${BAREOS_DIR_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR} \
			${BAREOS_DIR_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/bsr \
			${BAREOS_DIR_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/db/${PKG_SYSCONFSUBDIR}/storage \
			${BAREOS_DIR_USER} ${BAREOS_GROUP} 0770

post-install:
	${LN} -fs ${PKG_SYSCONFSUBDIR}/backends/libbareossd-gentape.so ${DESTDIR:Q}/${BAREOS_LIBDIR:Q}/libbareossd-gentape.so

CONFIG_TEMPLATES!=	${EGREP} "^"${CONFIG_TEMPLATE_PATH:Q}/ PLIST 2>/dev/null | sed -e 's/ /\\ /g'

CONF_FILES_PERMS?=
.for l in ${CONFIG_TEMPLATES}
CONF_FILES_PERMS+=	${l} ${PKG_SYSCONFDIR}${l:S/^${CONFIG_TEMPLATE_PATH}//} \
			${DIR_PERMS.${l:C,^${CONFIG_TEMPLATE_PATH}/([^/]+).*$,\1,}:U${DIR_PERMS}}
.endfor

D=
.for l in ${CONFIG_TEMPLATES:H:O:u}
.  if ${l} != ${CONFIG_TEMPLATE_PATH}
MAKE_DIRS_PERMS+=	${l:S/^${CONFIG_TEMPLATE_PATH}/${PKG_SYSCONFDIR}/} \
			${DIR_PERMS.${l:C,^${CONFIG_TEMPLATE_PATH}/([^/]+).*$,\1,}:U${DIR_PERMS}}
D+=			${l:C,^${CONFIG_TEMPLATE_PATH}/([^/]+).*$,${PKG_SYSCONFDIR}/\1,}
.  endif
.endfor

.for l in ${D:O:u}
MAKE_DIRS_PERMS+=	${l} \
			${DIR_PERMS.${l:C,^${PKG_SYSCONFDIR}/([^/]+).*$,\1,}:U${DIR_PERMS}}
.endfor
