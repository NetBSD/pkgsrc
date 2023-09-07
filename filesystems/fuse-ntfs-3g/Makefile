# $NetBSD: Makefile,v 1.23 2023/09/07 19:42:47 vins Exp $

PKGREVISION= 1
.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	fuse-${DISTNAME:S/_ntfsprogs//}
CATEGORIES=	filesystems

COMMENT=	NTFS driver with read and write support

CONFIGURE_ARGS+=	--disable-ldconfig
CONFIGURE_ARGS+=	--disable-ntfsprogs
CONFIGURE_ARGS+=	--enable-mount-helper

BUILD_DIRS=	src

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.include "../../filesystems/libntfs/buildlink3.mk"
.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
# fuse-ntfs-3g does not build with librefuse from netbsd-8.
# \todo Add a mechanism in mk/fuse.buildlink3.mk to declare this, rather
# than open-coding the changing of which bl3 line is used.
.include "../../filesystems/fuse/buildlink3.mk"
.else
# Find this platform's preferred FUSE implementation (normal approach). 
.include "../../mk/fuse.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
