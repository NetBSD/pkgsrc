# $NetBSD: Makefile,v 1.2 2001/02/16 13:30:46 wiz Exp $

DISTNAME=		mbr301h
PKGNAME=		mbrola-301h
CATEGORIES=		audio
MASTER_SITES=		ftp://tcts.fpms.ac.be/pub/mbrola/bsd/
EXTRACT_SUFX=		.zip

MAINTAINER=		proff@iq.org
HOMEPAGE=		http://tcts.fpms.ac.be/synthesis/
COMMENT=		MBROLA diphone synthesizer executable (only for i386)

BUILD_DEPENDS=		unzip:../../archivers/unzip

LICENSE=		no-commercial-use

EXTRACT_CMD=		unzip -Loq ${DOWNLOADED_DISTFILE}
NO_WRKSUBDIR=
NO_BUILD=

ONLY_FOR_PLATFORM=	NetBSD-*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbrola-netbsd-i386 ${PREFIX}/bin/mbrola
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mbrola
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/mbrola

.include "../../mk/bsd.pkg.mk"
