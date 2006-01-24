# $NetBSD: Makefile,v 1.14 2006/01/24 14:53:40 ghen Exp $

CONFLICTS+=		bacula-client-[0-9]*

.include "options.mk"

PLIST_SRC=		PLIST.common
PLIST_SRC+=		PLIST.server

PLIST_SUBST+=		BACULA_DB=${BACULA_DB:Q}
MESSAGE_SUBST+=		PREFIX=${PREFIX:Q}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}

CONFIGURE_ARGS+=	--with-dir-user=${BACULA_DIR_USER:Q} --with-dir-group=${BACULA_GROUP:Q}
CONFIGURE_ARGS+=	--with-sd-user=${BACULA_SD_USER:Q} --with-sd-group=${BACULA_GROUP:Q}

BUILD_DEFS+=		BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP

PKG_USERS=		${BACULA_DIR_USER}:${BACULA_GROUP}
PKG_USERS+=		${BACULA_SD_USER}:${BACULA_GROUP}

CONF_FILES+=		${EXAMPLESDIR}/bacula-dir.conf ${PKG_SYSCONFDIR}/bacula-dir.conf
CONF_FILES+=		${EXAMPLESDIR}/bacula-sd.conf ${PKG_SYSCONFDIR}/bacula-sd.conf

RCD_SCRIPTS=		bacula bacula-dir bacula-sd bacula-fd

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
