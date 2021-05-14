# $NetBSD: Makefile,v 1.5 2021/05/14 12:34:11 nia Exp $

PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-initiator/}
CATEGORIES=	net
COMMENT=	NetBSD's iSCSI initiator (per iSCSI RFC 3720)

BUILD_DIRS+=	src/initiator
DISTINFO_FILE=	${.CURDIR}/../../devel/netbsd-iscsi-lib/distinfo
PATCHDIR=	${.CURDIR}/../../devel/netbsd-iscsi-lib/patches

CPPFLAGS.NetBSD+=	-D_KERNTYPES

.include "../../devel/netbsd-iscsi-lib/Makefile.common"

.include "../../devel/netbsd-iscsi-lib/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
