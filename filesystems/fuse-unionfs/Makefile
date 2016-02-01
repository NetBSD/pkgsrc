# $NetBSD: Makefile,v 1.5 2016/02/01 02:41:21 jmmv Exp $
#

DISTNAME=	v1.0
DIST_SUBDIR=	${PKGBASE}
PKGNAME=	fuse-unionfs-${DISTNAME:S/v//}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpodgorny/unionfs-fuse/archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpodgorny/unionfs-fuse
COMMENT=	FUSE-based union filesystem

BUILD_TARGET=	build
USE_TOOLS=	gmake pkg-config
WRKSRC=		${WRKDIR}/unionfs-fuse-${DISTNAME:S/v//}

INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unionfs \
		${DESTDIR}${PREFIX}/bin/unionfs
	${INSTALL_PROGRAM} ${WRKSRC}/src/unionfsctl \
		${DESTDIR}${PREFIX}/bin/unionfsctl
	${INSTALL_MAN} ${WRKSRC}/man/unionfs.8 \
		${DESTDIR}${PREFIX}/man/man8

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
