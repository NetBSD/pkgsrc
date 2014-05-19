# $NetBSD: Makefile,v 1.12 2014/05/19 12:22:06 adam Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	${DISTNAME:S/ntfs-3g_//}
CATEGORIES=	sysutils

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--disable-ntfs-3g

BUILD_DIRS=		ntfsprogs

.include "../../devel/libuuid/buildlink3.mk"
.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
