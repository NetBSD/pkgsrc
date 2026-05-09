# $NetBSD: Makefile,v 1.4 2026/05/09 20:26:47 vins Exp $

.include "Makefile.common"

PKGNAME=	lib${DISTNAME:S/-3g_ntfsprogs//}

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--disable-ntfs-3g
CONFIGURE_ARGS+=	--disable-ntfsprogs

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.pkg.mk"
