# $NetBSD: Makefile,v 1.18 2012/09/08 12:36:57 shattered Exp $

PKGNAME=		${DISTNAME:S/-/-clientonly-/}
COMMENT=		The Network Backup Solution (client only)

PKGREVISION=		1

CONFLICTS=		bacula-[0-9]* bacula-client-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches
FILESDIR=		${.CURDIR}/../../sysutils/bacula/files

PLIST_SRC=		${.CURDIR}/../../sysutils/bacula/PLIST.common

CONFIGURE_ARGS+=	--enable-client-only

OWN_DIRS_PERMS+=	${BACULA_WORKINGDIR} root ${BACULA_GROUP} 770

PKG_GROUPS=		${BACULA_GROUP}

CONF_FILES+=		${EXAMPLESDIR}/bacula-fd.conf ${PKG_SYSCONFDIR}/bacula-fd.conf
CONF_FILES+=		${EXAMPLESDIR}/bconsole.conf ${PKG_SYSCONFDIR}/bconsole.conf

RCD_SCRIPTS=		bacula-fd

.include "../../sysutils/bacula/Makefile.common"

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/dvd-handler ${DESTDIR}${EXAMPLESDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
