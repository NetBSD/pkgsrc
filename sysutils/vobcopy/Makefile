# $NetBSD: Makefile,v 1.2 2004/04/18 23:01:23 snj Exp $
#

DISTNAME=	vobcopy-0.5.13
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

ALL_TARGET=	vobcopy
USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${PREFIX}/man/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
