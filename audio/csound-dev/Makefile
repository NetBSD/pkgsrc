# $NetBSD: Makefile,v 1.8 2004/04/13 09:38:38 xtraeme Exp $
#

DISTNAME=		Csound-4.24.1
PKGNAME=		csound-dev-4.24.1
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.csounds.com/istvan/archive/misc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Software synthesizer and sequencer

LICENSE=		csound-license
RESTRICTED=		"no for-fee-redistribution"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64	# many LP64 problems

DIST_SUBDIR=		csound
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_X11=		yes
CONFLICTS=		csound-bath*

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
