# $NetBSD: Makefile,v 1.13 2003/12/14 03:03:32 ben Exp $
#

DISTNAME=		Csound4.23
PKGNAME=		csound-bath-4.23
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DIST_SUBDIR=		csound
CONFLICTS=		csound-dev-4*
USE_GMAKE=		yes

pre-patch:
	 ${CP} ${FILESDIR}/rtNetBSD.c ${FILESDIR}/rtNetBSD.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
