# $NetBSD: Makefile,v 1.1.1.1 2007/02/20 23:00:08 xtraeme Exp $
#

DISTNAME=	LZOlayer_fs-20060306
PKGNAME=	fuse-${DISTNAME:S/LZOlayer_fs/lzofs/}
CATEGORIES=	sysutils
MASTER_SITES=	http://north.one.pl/~kazik/pub/LZOlayer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://north.one.pl/~kazik/pub/LZOlayer/
COMMENT=	Filesystem which allows you to use transparently compressed files

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
BUILD_TARGET=	default

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lzo_fs ${PREFIX}/bin/lzo_fs

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
