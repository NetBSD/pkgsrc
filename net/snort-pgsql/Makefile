# $NetBSD: Makefile,v 1.12 2003/12/31 14:11:42 salo Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}

COMMENT=	Network Intrusion Detection System (with PostgreSQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
