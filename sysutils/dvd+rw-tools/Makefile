# $NetBSD: Makefile,v 1.29 2008/04/23 15:35:50 wiz Exp $
#

DISTNAME=	dvd+rw-tools-7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{cdrtools-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
USE_TOOLS+=	m4

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# These are the only platforms listed in growisofs.c
ONLY_FOR_PLATFORM=Linux-*-* OpenBSD-*-* NetBSD-*-* FreeBSD-*-* \
	DragonFly-*-* SunOS-*-* HP-UX-*-* IRIX-*-*

LDFLAGS.NetBSD+=	-lrt # sem_* functions

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/growisofs ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/growisofs.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-booktype ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-format ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dvd+rw-mediainfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/dvd+rw-tools
	${INSTALL_DATA} ${WRKSRC}/index.html \
		${DESTDIR}${PREFIX}/share/doc/dvd+rw-tools

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
