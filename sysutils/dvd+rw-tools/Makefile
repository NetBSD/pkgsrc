# $NetBSD: Makefile,v 1.15 2005/12/05 20:51:00 rillig Exp $
#

DISTNAME=	dvd+rw-tools-5.21.4.10.8
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

DEPENDS+=	{cdrecord-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrecord

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin man/man1

# These are the only platforms listed in growisofs.c
ONLY_FOR_PLATFORM=Linux-*-* OpenBSD-*-* NetBSD-*-* FreeBSD-*-* \
	DragonFly-*-* SunOS-*-* HP-UX-*-* IRIX-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-mediainfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/dvd+rw-tools

.include "../../mk/bsd.pkg.mk"
