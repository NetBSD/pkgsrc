# $NetBSD: Makefile,v 1.10 2008/03/03 19:21:38 jlam Exp $

DISTNAME=	m1074b2-lnx
PKGNAME=	m1-0.7.4c
PKGREVISION=	2
CATEGORIES=	emulators audio
MASTER_SITES=	http://www.emuhype.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emuhype.com/index.phtml?s=misc&ss=index
COMMENT=	Arcade video and pinball game sound emulator (Linux binary)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/m1-0.7.4
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/m1 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/m1
	${INSTALL_DATA} ${WRKSRC}/m1.txt ${DESTDIR}${PREFIX}/share/doc/m1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/m1
	${INSTALL_DATA} ${WRKSRC}/m1.ini ${DESTDIR}${PREFIX}/share/examples/m1

.include "../../mk/bsd.pkg.mk"
