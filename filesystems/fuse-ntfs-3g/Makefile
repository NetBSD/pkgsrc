# $NetBSD: Makefile,v 1.18 2014/09/10 12:15:15 joerg Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	fuse-${DISTNAME:S/_ntfsprogs//}
CATEGORIES=	filesystems

COMMENT=	NTFS driver with read and write support

CONFIGURE_ARGS+=	--disable-ntfsprogs
CONFIGURE_ARGS+=	--enable-mount-helper

BUILD_DIRS=		src

USE_TOOLS+=	pkg-config

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
