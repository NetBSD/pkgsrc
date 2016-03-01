# $NetBSD: Makefile,v 1.4 2016/03/01 20:10:21 joerg Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-initiator/}
CATEGORIES=	net
COMMENT=	NetBSD's iSCSI initiator (per iSCSI RFC 3720)

BUILD_DIRS+=	src/initiator
DISTINFO_FILE=	${.CURDIR}/../../devel/netbsd-iscsi-lib/distinfo
PATCHDIR=	${.CURDIR}/../../devel/netbsd-iscsi-lib/patches

CPPFLAGS.NetBSD+=	-D_KERNTYPES

.include "../../devel/netbsd-iscsi-lib/Makefile.common"

.include "../../devel/netbsd-iscsi-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
