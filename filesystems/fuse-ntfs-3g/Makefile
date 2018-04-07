# $NetBSD: Makefile,v 1.20 2018/04/07 19:46:21 adam Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	fuse-${DISTNAME:S/_ntfsprogs//}
CATEGORIES=	filesystems

COMMENT=	NTFS driver with read and write support

CONFIGURE_ARGS+=	--disable-ntfsprogs
CONFIGURE_ARGS+=	--enable-mount-helper

NOT_FOR_PLATFORM=	NetBSD-*-* # ancient fuse API

BUILD_DIRS=	src

USE_TOOLS+=	pkg-config

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
