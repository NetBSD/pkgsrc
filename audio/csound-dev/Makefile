# $NetBSD: Makefile,v 1.1 2003/12/13 20:26:03 ben Exp $
#

DISTNAME=		Csound-4.24.1
PKGNAME=		csound-dev-4.24.1
CATEGORIES=		audio
MASTER_SITES=		http://www.csounds.com/istvan/archive/misc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64	# many LP64 problems

DIST_SUBDIR=		csound
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
CONFLICTS=		csound-bath*

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
