# $NetBSD: Makefile,v 1.5 2001/09/09 20:36:13 agc Exp $

DISTNAME=		mbr301h
PKGNAME=		mbrola-301h
CATEGORIES=		audio
MASTER_SITES=		http://www.festvox.org/mbrola/bin/netbsd/
EXTRACT_SUFX=		.zip

MAINTAINER=		proff@iq.org
HOMEPAGE=		http://www.festvox.org/mbrola/
COMMENT=		MBROLA diphone synthesizer executable

LICENSE=		no-commercial-use

DIST_SUBDIR=		mbrola-20010717
WRKSRC=			${WRKDIR}
NO_BUILD=

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

.if ( ${OBJECT_FMT} != "a.out" )
DEPENDS+=		compat14>=1.4.3:../../emulators/compat14
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbrola-netbsd-i386 ${PREFIX}/bin/mbrola
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mbrola
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
