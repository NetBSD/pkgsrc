# $NetBSD: Makefile,v 1.7.2.1 2003/03/07 07:47:08 jmc Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Libpcap-based packet sniffer/logger using a PostgreSQL database

USE_BUILDLINK2=	YES

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

CONFIGURE_ARGS+=--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}

PKGDIR=		${.CURDIR}/../../net/snort
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
