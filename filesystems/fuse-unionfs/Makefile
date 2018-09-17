# $NetBSD: Makefile,v 1.8 2018/09/17 14:33:35 leot Exp $

DISTNAME=	unionfs-fuse-2.0
PKGNAME=	${DISTNAME:S/unionfs-fuse/fuse-unionfs/}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpodgorny/}
GITHUB_PROJECT=	unionfs-fuse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpodgorny/unionfs-fuse
COMMENT=	FUSE-based union filesystem
LICENSE=	modified-bsd

BUILD_TARGET=	build
USE_TOOLS+=	gmake pkg-config bash:run

REPLACE_BASH+=	mount.unionfs

MAKE_ENV+=		MANDIR=${PKGMANDIR}

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
