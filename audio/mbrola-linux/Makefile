# $NetBSD: Makefile,v 1.4 1999/04/15 14:53:10 proff Exp $

DISTNAME=	mbrola-linux-301g1
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/pclinux/
DISTFILES=	mbr301g1.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://tcts.fpms.ac.be/synthesis/

BUILD_DEPENDS=	unzip:../../archivers/unzip

LICENSE=	non-commercial-use

EXTRACT_CMD=	unzip ${DOWNLOADED_DISTFILE} 

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes

do-install:
# INSTALL_PROGRAM attempts to strip the targer, however
# strip doesn't know how to strip linux binraries, so
# use INSTALL_SCRIPT instead
	${INSTALL_SCRIPT} ${WRKSRC}/mbrola ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
