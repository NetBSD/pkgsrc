# $NetBSD: Makefile,v 1.14 2004/04/10 03:11:17 snj Exp $

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}
PKGREVISION=	1

COMMENT=	Network Intrusion Detection System (with PostgreSQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
