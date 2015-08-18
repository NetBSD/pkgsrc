# $NetBSD: Makefile,v 1.10 2015/08/18 07:31:18 wiz Exp $
#

DISTNAME=		testdisk-6.14
PKGREVISION=		2
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

# testdisk uses either ntfsprogs or fuse-ntfs-3g, but not both, and prefers
# fuse-ntfs-3g.  Ignore configure-time warnings that the ntfs library is
# disabled.
.include "../../filesystems/libntfs/buildlink3.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
