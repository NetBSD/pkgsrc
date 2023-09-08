# $NetBSD: Makefile,v 1.2 2023/09/08 10:23:07 vins Exp $

.include "Makefile.common"

PKGNAME=	lib${DISTNAME:S/-3g_ntfsprogs//}

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--disable-ntfs-3g
CONFIGURE_ARGS+=	--disable-ntfsprogs

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.pkg.mk"
