# $NetBSD: Makefile,v 1.7 2003/07/26 11:13:49 salo Exp $
#

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-mysql-/}

COMMENT=	Network Intrusion Detection System (with MySQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-pgsql-[0-9]*

USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
