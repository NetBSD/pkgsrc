# $NetBSD: Makefile,v 1.3 1999/12/28 04:20:02 wiz Exp $

DISTNAME=	festvox_us3
PKGNAME=	festvox-us3-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.4.0:../festival \
		festlex-poslex-1.4.0:../festlex-poslex \
		festlex-cmu-1.4.0:../festlex-cmu \
		mbrola-301h:../mbrola \
		mbrolavox-us3-990208:../mbrolavox-us3

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us3_mbrola

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us3 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us3/us3mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
