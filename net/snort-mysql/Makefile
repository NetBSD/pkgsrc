# $NetBSD: Makefile,v 1.11 2004/10/29 05:59:24 jdolecek Exp $

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-mysql-/}
PKGREVISION=	1

COMMENT=	Network Intrusion Detection System (with MySQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-pgsql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}

.include "../../mk/mysql.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
