# $NetBSD: Makefile,v 1.5 2002/03/23 02:22:59 wiz Exp $
#

DISTNAME=		Csound4.18
PKGNAME=		csound-bath-4.18
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.csound.org
COMMENT=		software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		csound
CONFLICTS=		csound-4*

pre-patch:
	 ${CP} ${FILESDIR}/rtNetBSD.c ${FILESDIR}/rtNetBSD.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
