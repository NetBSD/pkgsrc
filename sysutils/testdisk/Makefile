# $NetBSD: Makefile,v 1.11 2015/08/24 19:54:14 leot Exp $
#

DISTNAME=		testdisk-7.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cgsecurity.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cgsecurity.org/wiki/TestDisk
COMMENT=		Tool to check and undelete partitions
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../devel/libuuid/buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--disable-qt

# testdisk uses either ntfsprogs or fuse-ntfs-3g, but not both, and prefers
# fuse-ntfs-3g.  Ignore configure-time warnings that the ntfs library is
# disabled.
.include "../../filesystems/libntfs/buildlink3.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
