# $NetBSD: Makefile,v 1.16 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=		Csound4.23
PKGNAME=		csound-bath-4.23
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		csound
CONFLICTS=		csound-dev-4*
USE_GNU_TOOLS+=		make

pre-patch:
	 ${CP} ${FILESDIR}/rtNetBSD.c ${FILESDIR}/rtNetBSD.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
