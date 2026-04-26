# $NetBSD: Makefile,v 1.14 2026/04/26 04:29:44 wiz Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	${DISTNAME:S/ntfs-3g_//}
PKGREVISION=	1
CATEGORIES=	sysutils

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--enable-extras
CONFIGURE_ARGS+=	--disable-ntfs-3g

BUILD_DIRS=		ntfsprogs

.include "../../devel/libuuid/buildlink3.mk"
.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
