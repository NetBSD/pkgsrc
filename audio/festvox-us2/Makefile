# $NetBSD: Makefile,v 1.3 1999/12/28 04:20:02 wiz Exp $

DISTNAME=	festvox_us2
PKGNAME=	festvox-us2-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.4.0:../festival \
		festlex-poslex-1.4.0:../festlex-poslex \
		festlex-cmu-1.4.0:../festlex-cmu \
		mbrola-301h:../mbrola \
		mbrolavox-us2-980812:../mbrolavox-us2

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us2_mbrola

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us2 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us2/us2mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
