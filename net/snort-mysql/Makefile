# $NetBSD: Makefile,v 1.3 2003/03/14 19:37:54 jlam Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-mysql-/}

COMMENT=        Libpcap-based packet sniffer/logger using a MySQL database

CONFLICTS+=     snort-[0-9]*
CONFLICTS+=     snort-pgsql-[0-9]*

CONFIGURE_ARGS+=--with-mysql=${BUILDLINK_PREFIX.mysql-client}

USE_BUILDLINK2=	YES

PKGDIR=         ${.CURDIR}/../../net/snort
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=       ${BUILDLINK_LDFLAGS.mysql-client}

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
