# $NetBSD: Makefile,v 1.12 2008/07/13 16:14:00 tonnerre Exp $
#

DISTNAME=	vobcopy-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://lpn.rnbhq.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpn.rnbhq.org/projects/c/c.shtml
COMMENT=	Copies DVD .vob files to harddisk

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	vobcopy

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vobcopy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/vobcopy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
