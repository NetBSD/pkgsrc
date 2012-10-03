# $NetBSD: Makefile,v 1.13 2012/10/03 12:55:15 asau Exp $
#

DISTNAME=	m1077b-lnx
PKGNAME=	m1-0.7.7
CATEGORIES=	emulators audio
MASTER_SITES=	http://www.emuhype.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emuhype.com/index.phtml?s=misc&ss=index
COMMENT=	Arcade video and pinball game sound emulator (Linux binary)

EMUL_PLATFORMS=	linux-i386
EMUL_MODULES.linux= alsa base resmgr

WRKSRC=		${WRKDIR}/m1-0.7.7

INSTALLATION_DIRS=	bin share/doc/m1 share/examples/m1

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/m1 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/m1.txt ${DESTDIR}${PREFIX}/share/doc/m1
	${INSTALL_DATA} ${WRKSRC}/m1.ini ${DESTDIR}${PREFIX}/share/examples/m1

.include "../../mk/bsd.pkg.mk"
