# $NetBSD: Makefile,v 1.5 2020/05/06 14:04:30 adam Exp $

DISTNAME=	gstfs-ng-1.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=rtyle/}
GITHUB_PROJECT=	gstfs-ng
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtyle/gstfs-ng
COMMENT=	FUSE-based file system for dynamic gstreamer-based transcoding
LICENSE=	gnu-lgpl-v3

SUPERSEDES+=	fuse-gstfs-[0-9]*

USE_TOOLS+=	pkg-config bash:run
USE_LANGUAGES=	c c++03

REPLACE_BASH+=	gstfs-ng.monitor

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gstfs-ng ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gstfs-ng.monitor ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gstfs-ng.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
