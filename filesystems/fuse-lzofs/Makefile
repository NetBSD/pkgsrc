# $NetBSD: Makefile,v 1.4 2012/10/03 16:08:32 asau Exp $
#

DISTNAME=	LZOlayer_fs-20060306
PKGNAME=	fuse-${DISTNAME:S/LZOlayer_fs/lzofs/}
CATEGORIES=	filesystems
MASTER_SITES=	http://north.one.pl/~kazik/pub/LZOlayer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://north.one.pl/~kazik/pub/LZOlayer/
COMMENT=	Filesystem which allows you to use transparently compressed files

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzo_fs ${DESTDIR}${PREFIX}/bin/lzo_fs

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
