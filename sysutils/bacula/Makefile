# $NetBSD: Makefile,v 1.19.2.1 2007/01/04 14:36:06 salo Exp $

CONFLICTS+=		bacula-client-[0-9]* bacula-clientonly-[0-9]*

.include "options.mk"

PLIST_SRC=		PLIST.common
PLIST_SRC+=		PLIST.server

PLIST_SUBST+=		BACULA_DB=${BACULA_DB:Q}
MESSAGE_SUBST+=		PREFIX=${PREFIX:Q}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}

CONFIGURE_ARGS+=	--with-dir-user=${BACULA_DIR_USER:Q} --with-dir-group=${BACULA_GROUP:Q}
CONFIGURE_ARGS+=	--with-sd-user=${BACULA_SD_USER:Q} --with-sd-group=${BACULA_GROUP:Q}

BUILD_DEFS+=		BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP

OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} ${ROOT_USER} ${BACULA_GROUP} 770

PKG_USERS=		${BACULA_DIR_USER}:${BACULA_GROUP}
PKG_USERS+=		${BACULA_SD_USER}:${BACULA_GROUP}
PKG_GROUPS=		${BACULA_GROUP}

CONF_FILES+=		${EXAMPLESDIR}/bacula-fd.conf ${PKG_SYSCONFDIR}/bacula-fd.conf
CONF_FILES+=		${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf
CONF_FILES+=		${EXAMPLESDIR}/bacula-dir.conf ${PKG_SYSCONFDIR}/bacula-dir.conf
CONF_FILES+=		${EXAMPLESDIR}/bacula-sd.conf ${PKG_SYSCONFDIR}/bacula-sd.conf

RCD_SCRIPTS=		bacula bacula-dir bacula-sd bacula-fd

.include "Makefile.common"

PLIST_SRC+=		PLIST.common_end

.include "../../mk/bsd.pkg.mk"
