# $NetBSD: Makefile,v 1.2 1999/12/25 22:39:02 wiz Exp $

DISTNAME=	festvox_us1
PKGNAME=	festvox-us1-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.4.0:../festival \
		festlex-poslex-1.4.0:../festlex-poslex \
		festlex-cmu-1.4.0:../festlex-cmu \
		mbrola-301h:../mbrola \
		mbrolavox-us1-980512:../mbrolavox-us1

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us1_mbrola

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}
#ugh
	ln -fs ../../../../../mbrola/voices/us1 ${MBROLA}
	ln -fs ../../../../../mbrola/voices/us1/us1mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
