# $NetBSD: Makefile,v 1.6 1999/06/09 17:05:36 agc Exp $

DISTNAME=		mbrola-linux-301g1
CATEGORIES=		audio
MASTER_SITES=		ftp://tcts.fpms.ac.be/pub/mbrola/pclinux/
EXTRACT_SUFX=		.zip

MAINTAINER=		proff@iq.org
HOMEPAGE=		http://tcts.fpms.ac.be/synthesis/

BUILD_DEPENDS=		unzip:../../archivers/unzip

LICENSE=		no-commercial-use

EXTRACT_CMD=		unzip -Loq ${DOWNLOADED_DISTFILE}
NO_WRKSUBDIR=
NO_BUILD=

ONLY_FOR_PLATFORM=	NetBSD-*-i386

# Do not strip Linux binaries.
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mbrola ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
