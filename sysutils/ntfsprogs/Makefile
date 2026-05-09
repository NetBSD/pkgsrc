# $NetBSD: Makefile,v 1.15 2026/05/09 20:26:47 vins Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	${DISTNAME:S/ntfs-3g_//}
CATEGORIES=	sysutils

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--enable-extras
CONFIGURE_ARGS+=	--disable-ntfs-3g

BUILD_DIRS=		ntfsprogs

.include "../../devel/libuuid/buildlink3.mk"
.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
