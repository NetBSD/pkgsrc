# $NetBSD: Makefile,v 1.11 2003/07/26 11:13:50 salo Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Network Intrusion Detection System (with PostgreSQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
