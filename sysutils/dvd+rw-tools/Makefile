# $NetBSD: Makefile,v 1.8 2004/03/31 08:50:25 wiz Exp $
#

DISTNAME=	dvd+rw-tools-5.17.4.8.6
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

DEPENDS+=	{cdrecord-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrecord

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-mediainfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/html/dvd+rw-tools

.include "../../mk/bsd.pkg.mk"
