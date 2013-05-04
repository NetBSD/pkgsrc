# $NetBSD: Makefile,v 1.4 2013/05/04 12:38:28 dsainty Exp $
#

DISTNAME=		testdisk-6.13
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cgsecurity.org/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cgsecurity.org/wiki/TestDisk
COMMENT=		Tool to check and undelete partitions
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

# testdisk uses either ntfsprogs or fuse-ntfs-3g, but not both, and prefers
# fuse-ntfs-3g.  Ignore configure-time warnings that the ntfs library is
# disabled.

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../filesystems/fuse-ntfs-3g/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
