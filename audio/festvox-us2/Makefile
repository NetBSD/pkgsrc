# $NetBSD: Makefile,v 1.11 2004/01/20 12:07:42 agc Exp $

DISTNAME=	festvox_us2
PKGNAME=	festvox-us2-1.4.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	MBROLA based Americal English male voice for festival

DEPENDS+=	festival>=1.4.0:../festival
DEPENDS+=	festlex-poslex>=1.4.0:../festlex-poslex
DEPENDS+=	festlex-cmu>=1.4.0:../festlex-cmu
DEPENDS+=	mbrola-301h:../mbrola
DEPENDS+=	mbrolavox-us2-980812:../mbrolavox-us2

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us2_mbrola

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us2 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us2/us2mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
