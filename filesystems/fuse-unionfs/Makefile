# $NetBSD: Makefile,v 1.6 2017/08/19 00:20:50 jlam Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unionfs \
		${DESTDIR}${PREFIX}/bin/unionfs
	${INSTALL_PROGRAM} ${WRKSRC}/src/unionfsctl \
		${DESTDIR}${PREFIX}/bin/unionfsctl
	${INSTALL_MAN} ${WRKSRC}/man/unionfs.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
