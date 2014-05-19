# $NetBSD: Makefile,v 1.1 2014/05/19 12:22:06 adam Exp $

.include "Makefile.common"

PKGNAME=	lib${DISTNAME:S/-3g_ntfsprogs//}
CATEGORIES=	sysutils

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--disable-ntfs-3g
CONFIGURE_ARGS+=	--disable-ntfsprogs

.include "../../mk/bsd.pkg.mk"
