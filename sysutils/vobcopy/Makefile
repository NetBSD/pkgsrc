# $NetBSD: Makefile,v 1.1.1.1 2004/04/08 14:17:57 drochner Exp $
#

DISTNAME=	vobcopy-0.5.13
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

ALL_TARGET=	vobcopy
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${PREFIX}/man/man1

.include "../../multimedia/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
