# $NetBSD: Makefile,v 1.5 2005/01/17 03:28:06 minskim Exp $
#

DISTNAME=	vobcopy-0.5.13
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=	vobcopy
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${PREFIX}/man/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
