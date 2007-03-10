# $NetBSD: Makefile,v 1.1.1.1 2007/03/10 12:51:03 agc Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unionfs ${PREFIX}/bin/fuse-unionfs

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
