# $NetBSD: Makefile,v 1.18 2012/10/02 23:47:57 asau Exp $

DISTNAME=		mbr301h
PKGNAME=		mbrola-301h
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://tcts.fpms.ac.be/synthesis/mbrola/bin/netbsd/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=		MBROLA diphone synthesizer executable
LICENSE=		no-commercial-use

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		mbrola-20010717
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		netbsd-i386
EMUL_REQD=		netbsd>=1.4
EMUL_MODULES.netbsd=	base

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbrola-netbsd-i386 \
		${DESTDIR}${PREFIX}/bin/mbrola
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mbrola
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
