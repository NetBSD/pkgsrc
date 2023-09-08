# $NetBSD: Makefile,v 1.13 2023/09/08 10:23:07 vins Exp $

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
