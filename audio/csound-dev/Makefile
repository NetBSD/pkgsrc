# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:05 tv Exp $
#

DISTNAME=		Csound-4.24.1
PKGNAME=		csound-dev-4.24.1
PKGREVISION=		2
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
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		defbsd
SUBST_MESSAGE.defbsd=	"Configuring to use NetBSD presets."
SUBST_STAGE.defbsd=	post-patch
SUBST_FILES.defbsd=	Makefile.defs
SUBST_SED.defbsd=	-e 's,^\(DEFINES =\),\1 -DBSD,'
.endif

pre-install:
			${RM} -f ${WRKSRC}/include/Csound/sysdep.h.orig

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
