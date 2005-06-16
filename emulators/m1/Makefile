# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:51 jlam Exp $
#

DISTNAME=	m1074b2-lnx
PKGNAME=	m1-0.7.4c
CATEGORIES=	emulators audio
MASTER_SITES=	http://www.emuhype.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.emuhype.com/index.phtml?s=misc&ss=index
COMMENT=	Arcade video and pinball game sound emulator (Linux binary)

DEPENDS+=	suse_base>=6.4:../../emulators/${SUSE_DIR_PREFIX}_compat

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=		${WRKDIR}/m1-0.7.4
NO_BUILD=	# defined
CHECK_SHLIBS=	no

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/m1 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/m1
	${INSTALL_DATA} ${WRKSRC}/m1.txt ${PREFIX}/share/doc/m1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/m1
	${INSTALL_DATA} ${WRKSRC}/m1.ini ${PREFIX}/share/examples/m1

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
