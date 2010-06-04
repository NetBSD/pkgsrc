# $NetBSD: Makefile,v 1.2 2010/06/04 16:24:56 sborrill Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-target/}
CATEGORIES=	net
COMMENT=	NetBSD's iSCSI target (per iSCSI RFC 3720)

BUILD_DIRS+=	${WRKSRC}/src/target
DISTINFO_FILE=	${.CURDIR}/../../devel/netbsd-iscsi-lib/distinfo
PATCHDIR=	${.CURDIR}/../../devel/netbsd-iscsi-lib/patches

.include "../../devel/netbsd-iscsi-lib/Makefile.common"

.include "../../devel/netbsd-iscsi-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
