# $NetBSD: Makefile,v 1.5 2012/10/03 16:08:31 asau Exp $

DISTNAME=	fuse-ext2-0.0.7
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-ext2/fuse-ext2/${DISTNAME}/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://alperakcan.org/projects/fuse-ext2/
COMMENT=	FUSE file-system to mount ext2 and ext3 file system
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-* NetBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config
USE_LANGUAGES=	c c++
INSTALLATION_DIRS=	lib/umview/modules

pre-configure:
	cd ${WRKSRC} && autoreconf --verbose --install --force

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
