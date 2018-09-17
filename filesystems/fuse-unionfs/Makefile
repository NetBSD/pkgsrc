# $NetBSD: Makefile,v 1.7 2018/09/17 14:03:08 maya Exp $
#

DISTNAME=	v2.0
DIST_SUBDIR=	${PKGBASE}
PKGNAME=	fuse-unionfs-${DISTNAME:S/v//}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpodgorny/unionfs-fuse/archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpodgorny/unionfs-fuse
COMMENT=	FUSE-based union filesystem

BUILD_TARGET=	build
USE_TOOLS=	gmake pkg-config bash:run
WRKSRC=		${WRKDIR}/unionfs-fuse-${DISTNAME:S/v//}

REPLACE_BASH+=	mount.unionfs

MAKE_ENV+=		MANDIR=${PKGMANDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/fuse.buildlink3.mk"

pre-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	mkdir -p ${DESTDIR}${PREFIX}/sbin
	mkdir -p ${DESTDIR}${PREFIX}${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
