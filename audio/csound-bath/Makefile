# $NetBSD: Makefile,v 1.12 2003/12/13 20:14:26 ben Exp $
#

DISTNAME=		Csound4.23
PKGNAME=		csound-bath-4.23
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.csound.org/
COMMENT=		Software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DIST_SUBDIR=		csound
CONFLICTS=		csound-4*
USE_GMAKE=		yes

pre-patch:
	 ${CP} ${FILESDIR}/rtNetBSD.c ${FILESDIR}/rtNetBSD.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
