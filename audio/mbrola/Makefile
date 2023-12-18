# $NetBSD: Makefile,v 1.20 2023/12/18 14:25:32 zafer Exp $

DISTNAME=		mbr301h
PKGNAME=		mbrola-301h
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://tcts.fpms.ac.be/synthesis/mbrola/bin/netbsd/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/numediart/MBROLA
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
	${INSTALL_DATA} ${WRKSRC}/mbrola-netbsd-i386 \
		${DESTDIR}${PREFIX}/bin/mbrola
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mbrola
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
