# $NetBSD: Makefile,v 1.33 2012/10/23 19:50:59 asau Exp $
#

DISTNAME=	dvd+rw-tools-7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://fy.chalmers.se/~appro/linux/DVD+RW/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fy.chalmers.se/~appro/linux/DVD+RW/
COMMENT=	Tools for writing DVD+R[W] disks
LICENSE=	gnu-gpl-v2

DEPENDS+=	{cdrtools-[1-9]*,cdrtools-ossdvd-[0-9]*}:../../sysutils/cdrtools

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
USE_TOOLS+=	m4 gmake

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
