# $NetBSD: Makefile,v 1.9 2003/07/19 08:54:25 wiz Exp $
#

DISTNAME=		Csound4.23
PKGNAME=		csound-bath-4.23
WRKSRC=			${WRKDIR}
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

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
