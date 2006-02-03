# $NetBSD: Makefile,v 1.5 2006/02/03 08:18:45 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-clientonly-/}
COMMENT=		The Network Backup Solution (client only)

CONFLICTS=		bacula-[0-9]* bacula-client-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches
FILESDIR=		${.CURDIR}/../../sysutils/bacula/files

PLIST_SRC=		${.CURDIR}/../../sysutils/bacula/PLIST.common

CONFIGURE_ARGS+=	--enable-client-only

BUILD_DEFS+=		BACULA_GROUP

OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} root ${BACULA_GROUP} 770

PKG_GROUPS=		${BACULA_GROUP}

CONF_FILES+=		${EXAMPLESDIR}/bacula-fd.conf ${PKG_SYSCONFDIR}/bacula-fd.conf
CONF_FILES+=		${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf

RCD_SCRIPTS=		bacula-fd

.include "../../sysutils/bacula/Makefile.common"

PLIST_SRC+=		${.CURDIR}/../../sysutils/bacula/PLIST.common_end

.include "../../mk/bsd.pkg.mk"
