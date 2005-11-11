# $NetBSD: Makefile,v 1.1.1.1 2005/11/11 21:31:39 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-clientonly-/}
COMMENT+=		client only

CONFLICTS=		bacula-[0-9]* bacula-client-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches
FILESDIR=		${.CURDIR}/../../sysutils/bacula/files

CONFIGURE_ARGS+=	--enable-client-only

RCD_SCRIPTS=		bacula-fd

.include "../../sysutils/bacula/Makefile.common"
.include "../../mk/bsd.pkg.mk"
