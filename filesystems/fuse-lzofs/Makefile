# $NetBSD: Makefile,v 1.8 2022/01/09 17:30:30 pho Exp $
#

DISTNAME=	LZOlayer_fs-20060306
PKGNAME=	fuse-${DISTNAME:S/LZOlayer_fs/lzofs/}
PKGREVISION=	2
CATEGORIES=	filesystems
#MASTER_SITES=	http://north.one.pl/~kazik/pub/LZOlayer/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://north.one.pl/~kazik/pub/LZOlayer/
COMMENT=	Filesystem which allows you to use transparently compressed files

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzo_fs ${DESTDIR}${PREFIX}/bin/lzo_fs

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
