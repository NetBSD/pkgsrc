# $NetBSD: Makefile,v 1.3 2026/04/26 04:29:43 wiz Exp $

.include "Makefile.common"

PKGNAME=	lib${DISTNAME:S/-3g_ntfsprogs//}
PKGREVISION=	1

COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

CONFIGURE_ARGS+=	--disable-ntfs-3g
CONFIGURE_ARGS+=	--disable-ntfsprogs

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.pkg.mk"
