# $NetBSD: Makefile,v 1.18 2006/01/03 17:34:40 adrianp Exp $

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

CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
