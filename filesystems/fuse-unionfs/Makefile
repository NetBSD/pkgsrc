# $NetBSD: Makefile,v 1.4 2012/10/03 16:08:32 asau Exp $
#

DISTNAME=	unionfs-fuse-0.17
PKGNAME=	fuse-unionfs-0.17
CATEGORIES=	filesystems
MASTER_SITES=	http://podgorny.cz/unionfs-fuse/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://podgorny.cz/unionfs-fuse/
COMMENT=	FUSE-based union filesystem

BUILD_TARGET=	unionfs
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unionfs \
		${DESTDIR}${PREFIX}/bin/fuse-unionfs

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
