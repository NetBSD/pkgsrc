# $NetBSD: Makefile,v 1.3 2013/04/06 15:46:38 rodent Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-initiator/}
CATEGORIES=	net
COMMENT=	NetBSD's iSCSI initiator (per iSCSI RFC 3720)

BUILD_DIRS+=	src/initiator
DISTINFO_FILE=	${.CURDIR}/../../devel/netbsd-iscsi-lib/distinfo
PATCHDIR=	${.CURDIR}/../../devel/netbsd-iscsi-lib/patches

.include "../../devel/netbsd-iscsi-lib/Makefile.common"

.include "../../devel/netbsd-iscsi-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
