# $NetBSD: Makefile,v 1.6 2004/03/12 02:20:17 snj Exp $
#

DISTNAME=		Csound-4.24.1
PKGNAME=		csound-dev-4.24.1
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
GCC_REQD=		3.0
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_X11=		yes
CONFLICTS=		csound-bath*

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
