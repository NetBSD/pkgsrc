# $NetBSD: Makefile,v 1.8 2003/03/04 01:02:26 salo Exp $
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
