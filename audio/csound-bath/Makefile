# $NetBSD: Makefile,v 1.17 2004/04/11 21:49:10 ben Exp $
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

.include "../../mk/bsd.prefs.mk"

pre-patch:
	 ${CP} ${FILESDIR}/rtNetBSD.c ${FILESDIR}/rtNetBSD.h ${WRKSRC}

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=	rtaudio
SUBST_MESSAGE.rtaudio=	"Configuring to use NetBSD real-time audio driver."
SUBST_STAGE.rtaudio=	post-patch
SUBST_FILES.rtaudio=	Makefile
SUBST_SED.rtaudio=	-e 's,^AUDSRC.*,AUDSRC = rtNetBSD.c,' \
			-e 's,^AUDOBJ.*,AUDOBJ = rtNetBSD.o,' \
			-e 's,^\(DEFINES.*\),\1 -DRTAUDIO -DNETBSDAUDIO,'
.endif

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=	rtaudio
SUBST_MESSAGE.rtaudio=	"Configuring to use Linux real-time audio driver."
SUBST_STAGE.rtaudio=	post-patch
SUBST_FILES.rtaudio=	Makefile
SUBST_SED.rtaudio=	-e 's,^AUDSRC.*,AUDSRC = rtlinux.c LINUXaudio.c,' \
			-e 's,^AUDOBJ.*,AUDOBJ = rtlinux.o LINUXaudio.o,' \
			-e 's,^\(DEFINES.*\),\1 -DRTAUDIO,' \
			-e 's,^\(LIBS.*\),\1 -ldl,'
.endif

.include "../../mk/bsd.pkg.mk"
