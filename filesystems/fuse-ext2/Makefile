# $NetBSD: Makefile,v 1.11 2020/08/11 13:38:14 nia Exp $

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

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/fuse.buildlink3.mk"
.include "../../sysutils/e2fsprogs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
