# $NetBSD: Makefile,v 1.3 2005/11/18 07:21:04 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-clientonly-/}
COMMENT=		The Network Backup Solution (client only)

CONFLICTS=		bacula-[0-9]* bacula-client-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches
FILESDIR=		${.CURDIR}/../../sysutils/bacula/files

CONFIGURE_ARGS+=	--enable-client-only

BUILD_DEFS+=		BACULA_GROUP

RCD_SCRIPTS=		bacula-fd

.include "../../sysutils/bacula/Makefile.common"
.include "../../mk/bsd.pkg.mk"
