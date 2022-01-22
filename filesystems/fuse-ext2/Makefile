# $NetBSD: Makefile,v 1.12 2022/01/22 18:34:51 pho Exp $

DISTNAME=	fuse-ext2-0.0.10
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=alperakcan/}
GITHUB_PROJECT=	fuse-ext2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alperakcan/fuse-ext2
COMMENT=	FUSE module to mount ext2, ext3, and ext4 filesystems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoheader automake autoreconf gmake pkg-config
USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	lib/umview/modules
CHECK_PORTABILITY_SKIP=	tools/macosx/fuse-ext2.fs/fuse-ext2.util

# fuse-ext2 does a weird hack defining FUSE_USE_VERSION to be
# FUSE_VERSION while FUSE 2.7 is what it actually needs. The hack
# isn't compatible with NetBSD librefuse. Please, just don't do that.
SUBST_CLASSES+=		fuse-ver
SUBST_STAGE.fuse-ver=	pre-configure
SUBST_FILES.fuse-ver=	configure.ac
SUBST_SED.fuse-ver=	-e 's/FUSE_VERSION/27/g'

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/fuse.buildlink3.mk"
.include "../../sysutils/e2fsprogs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
