# $NetBSD: Makefile,v 1.18 2006/01/31 19:01:28 xtraeme Exp $
#

DISTNAME=	dvd+rw-tools-6.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

DEPENDS+=	{cdrtools-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin man/man1

# These are the only platforms listed in growisofs.c
ONLY_FOR_PLATFORM=Linux-*-* OpenBSD-*-* NetBSD-*-* FreeBSD-*-* \
	DragonFly-*-* SunOS-*-* HP-UX-*-* IRIX-*-*

LIBS.NetBSD+=		-lrt # sem_* functions

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-mediainfo ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/dvd+rw-tools

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
