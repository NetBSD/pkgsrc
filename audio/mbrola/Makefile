# $NetBSD: Makefile,v 1.12 2006/10/14 07:59:09 wiz Exp $

DISTNAME=		mbr301h
PKGNAME=		mbrola-301h
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://tcts.fpms.ac.be/synthesis/mbrola/bin/netbsd/ \
			http://www.festvox.org/mbrola/bin/netbsd/
EXTRACT_SUFX=		.zip

MAINTAINER=		proff@iq.org
HOMEPAGE=		http://tcts.fpms.ac.be/synthesis/mbrola/
COMMENT=		MBROLA diphone synthesizer executable

LICENSE=		no-commercial-use

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		mbrola-20010717
NO_BUILD=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

.if ( ${OBJECT_FMT} != "a.out" )
DEPENDS+=		compat14{,-crypto}>=1.4.3:../../emulators/compat14
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbrola-netbsd-i386 ${PREFIX}/bin/mbrola
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mbrola
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
