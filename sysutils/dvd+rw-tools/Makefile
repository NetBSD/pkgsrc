# $NetBSD: Makefile,v 1.2 2003/05/03 07:08:37 salo Exp $
#

DISTNAME=	dvd+rw-tools-5.5.4.3.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@netbsd.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

DEPENDS+=	cdrecord-[1-9]*:../../sysutils/cdrecord

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/html/dvd+rw-tools

.include "../../mk/bsd.pkg.mk"
