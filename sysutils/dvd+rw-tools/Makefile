# $NetBSD: Makefile,v 1.11 2004/06/30 00:11:23 wiz Exp $
#

DISTNAME=	dvd+rw-tools-5.19-1.4.9.7
PKGNAME=	dvd+rw-tools-5.19.4.9.7
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

DEPENDS+=	{cdrecord-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrecord

WRKSRC=		${WRKDIR}/${PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-mediainfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/html/dvd+rw-tools

.include "../../mk/bsd.pkg.mk"
