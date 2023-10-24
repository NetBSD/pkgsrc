# $NetBSD: Makefile,v 1.4 2023/10/24 22:11:04 wiz Exp $

COMMENT=		Backup Archiving REcovery Open Sourced - client
PKGREVISION=		1

CONFLICTS=		bareos-[0-9]* bacula-[0-9]* bacula-clientonly-[0-9]*

.include "../../sysutils/bareos/Makefile.common"

CMAKE_ARGS?=
CMAKE_ARGS+=		-Dclient-only=true

RCD_SCRIPTS=		bareos-fd

PKGNAME=		${DISTNAME:S/-/-clientonly-/}

PATCHDIR=		${.CURDIR}/../../sysutils/bareos/patches
FILESDIR=		${.CURDIR}/../../sysutils/bareos/files
DISTINFO_FILE=		${.CURDIR}/../../sysutils/bareos/distinfo

# needs to be here to get ${EGREP} defined
.include "../../mk/bsd.pkg.mk"

CONFIG_TEMPLATES!=	${EGREP} "^"${CONFIG_TEMPLATE_PATH:Q} PLIST 2>/dev/null | sed -e 's/ /\\ /g'

BUILD_DEFS+=	VARBASE # to keep pkglint happy

DIR_PERMS.bareos-fd.d=	${REAL_ROOT_USER} ${BAREOS_GROUP} 0770
DIR_PERMS=		${REAL_ROOT_USER} ${BAREOS_GROUP} 0775

# spool directory
MAKE_DIRS_PERMS?=
MAKE_DIRS_PERMS+=	${VARBASE}/${PKG_SYSCONFSUBDIR} \
			${REAL_ROOT_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/${PKG_SYSCONFSUBDIR}/db \
			${REAL_ROOT_USER} ${BAREOS_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/${PKG_SYSCONFSUBDIR}/db/working \
			${REAL_ROOT_USER} ${BAREOS_GROUP} 0770

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
