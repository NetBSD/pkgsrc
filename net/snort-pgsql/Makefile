# $NetBSD: Makefile,v 1.4 2002/07/17 13:06:04 agc Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Libpcap-based packet sniffer/logger using a PostgreSQL database

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

CONFIGURE_ARGS+=--with-postgresql=${BUILDLINK_DIR}

PKGDIR=		${.CURDIR}/../../net/snort
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../net/libpcap/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
