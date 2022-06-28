# $NetBSD: Makefile,v 1.96 2022/06/28 11:35:53 wiz Exp $

CONFLICTS+=		bacula-client-[0-9]* bacula-clientonly-[0-9]* bareos-[0-9]* bareos-clientonly-[0-9]*

PKGREVISION=	8

.include "options.mk"

PLIST_SRC=		PLIST.common
PLIST_SRC+=		PLIST.server

PLIST_SUBST+=		BACULA_DB=${BACULA_DB}
MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}

# For make_catalog_backup.pl.in.
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-dir-group=${BACULA_GROUP}
CONFIGURE_ARGS+=	--with-dir-user=${BACULA_DIR_USER}
CONFIGURE_ARGS+=	--with-sd-group=${BACULA_GROUP}
CONFIGURE_ARGS+=	--with-sd-user=${BACULA_SD_USER}

OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} ${REAL_ROOT_USER} ${BACULA_GROUP} 770

PKG_USERS=		${BACULA_DIR_USER}:${BACULA_GROUP}
PKG_USERS+=		${BACULA_SD_USER}:${BACULA_GROUP}
PKG_GROUPS=		${BACULA_GROUP}

CONF_FILES+=		${EXAMPLESDIR}/bacula-fd.conf ${PKG_SYSCONFDIR}/bacula-fd.conf
CONF_FILES+=		${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf
CONF_FILES+=		${EXAMPLESDIR}/bacula-dir.conf ${PKG_SYSCONFDIR}/bacula-dir.conf
CONF_FILES+=		${EXAMPLESDIR}/bacula-sd.conf ${PKG_SYSCONFDIR}/bacula-sd.conf

RCD_SCRIPTS=		bacula bacula-dir bacula-sd bacula-fd

REPLACE_PERL+=		src/cats/make_catalog_backup.pl.in

.include "Makefile.common"

INSTALL_MAKE_FLAGS+=	dir_user= dir_group= sd_group=

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/chio-changer \
		${DESTDIR}${PREFIX}/libexec/bacula/

.include "../../mk/bsd.pkg.mk"
