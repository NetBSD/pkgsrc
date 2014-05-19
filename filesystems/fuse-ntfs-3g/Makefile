# $NetBSD: Makefile,v 1.17 2014/05/19 12:22:06 adam Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	fuse-${DISTNAME:S/_ntfsprogs//}
CATEGORIES=	filesystems

COMMENT=	NTFS driver with read and write support

CONFIGURE_ARGS+=	--disable-ntfsprogs
CONFIGURE_ARGS+=	--enable-mount-helper

BUILD_DIRS=		src

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
