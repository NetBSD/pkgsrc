# $NetBSD: Makefile,v 1.3 2020/11/05 09:09:05 ryoon Exp $

CONFLICTS=		bareos-clientonly-[0-9]* bacula-clientonly-[0-9]* bacula-[0-9]*

COMMENT=		Backup Archiving REcovery Open Sourced
PKGREVISION=		2

PLIST_SRC=		PLIST.common

RCD_SCRIPTS=		bareos bareos-dir bareos-sd bareos-fd

# For make_catalog_backup.pl.in.
USE_TOOLS+=		perl:run
# strange: pkglint complains about VARBASE not defined in BUILD_DEFS, but it is defined in Makefile.common
BUILD_DEFS+=		VARBASE

.include "options.mk"
.include "Makefile.common"

# needs to be here to get ${EGREP} defined
.include "../../mk/bsd.pkg.mk"

REPLACE_PERL+=		core/src/cats/make_catalog_backup.pl.in

# spool directory
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

CONFIG_TEMPLATES!=	${EGREP} "^"${CONFIG_TEMPLATE_PATH:Q} PLIST.common 2>/dev/null | sed -e 's/ /\\ /g'
CONF_FILES?=

.for l in ${CONFIG_TEMPLATES}
CONF_FILES+=	${l} ${PKG_SYSCONFDIR}${l:S/^${CONFIG_TEMPLATE_PATH}//}
.endfor

MAKE_DIRS?=
MAKE_DIRS+=	${CONFIG_TEMPLATES:H:O:u:S/^${CONFIG_TEMPLATE_PATH}/${PKG_SYSCONFDIR}/}
