# $NetBSD: Makefile,v 1.5 2002/10/10 12:26:53 wiz Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Libpcap-based packet sniffer/logger using a PostgreSQL database

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

CONFIGURE_ARGS+=--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}

PKGDIR=		${.CURDIR}/../../net/snort
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
