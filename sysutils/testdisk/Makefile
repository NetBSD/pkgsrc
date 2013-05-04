# $NetBSD: Makefile,v 1.5 2013/05/04 13:13:44 dsainty Exp $
#

DISTNAME=		testdisk-6.14-WIP
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
.include "../../filesystems/fuse-ntfs-3g/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
