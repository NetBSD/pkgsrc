# $NetBSD: Makefile,v 1.19 2015/11/10 17:45:22 adam Exp $

.include "../../filesystems/libntfs/Makefile.common"

PKGNAME=	fuse-${DISTNAME:S/_ntfsprogs//}
CATEGORIES=	filesystems

COMMENT=	NTFS driver with read and write support

CONFIGURE_ARGS+=	--disable-ntfsprogs
CONFIGURE_ARGS+=	--enable-mount-helper

BUILD_DIRS=		src

USE_TOOLS+=	pkg-config

PLIST_VARS+=	lowntfs
.include "../../mk/bsd.prefs.mk"
SUBST_CLASSES+=		lowntfs
SUBST_MESSAGE.lowntfs=	Dealing with lowntfs.
SUBST_STAGE.lowntfs=	pre-configure
SUBST_FILES.lowntfs=	src/Makefile.in
.if ${OPSYS} == "NetBSD"
SUBST_SED.lowntfs=	-e 's,@ENABLE_LOWNTFS@,\#,'
.else
SUBST_SED.lowntfs=	-e 's,@ENABLE_LOWNTFS@,,'
PLIST.lowntfs=		yes
.endif

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
