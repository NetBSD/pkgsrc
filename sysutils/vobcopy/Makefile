# $NetBSD: Makefile,v 1.15 2014/02/02 20:20:50 wiz Exp $

DISTNAME=	vobcopy-1.2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=	vobcopy

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
