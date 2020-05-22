# $NetBSD: Makefile,v 1.18 2020/05/22 12:43:53 adam Exp $

DISTNAME=	vobcopy-1.2.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

BUILD_TARGET=	vobcopy

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
