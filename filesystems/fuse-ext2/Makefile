# $NetBSD: Makefile,v 1.1.1.1 2011/07/09 15:27:11 tron Exp $

DISTNAME=	fuse-ext2-0.0.7
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-ext2/fuse-ext2/${DISTNAME}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alperakcan.org/projects/fuse-ext2/
COMMENT=	FUSE file-system to mount ext2 and ext3 file system
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-* NetBSD-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config
USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && autoreconf --verbose --install --force

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
