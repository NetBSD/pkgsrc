# $NetBSD: Makefile,v 1.6 2003/04/20 20:40:03 grant Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=        ${DISTNAME:S/-/-mysql-/}
PKGREVISION=	1

COMMENT=        Libpcap-based packet sniffer/logger using a MySQL database

CONFLICTS+=     snort-[0-9]*
CONFLICTS+=     snort-pgsql-[0-9]*

CONFIGURE_ARGS+=--with-mysql=${BUILDLINK_PREFIX.mysql-client}

USE_BUILDLINK2=	YES

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=       ${BUILDLINK_LDFLAGS.mysql-client}

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
