# $NetBSD: Makefile,v 1.11 2004/01/20 12:07:42 agc Exp $

DISTNAME=	festvox_us3
PKGNAME=	festvox-us3-1.4.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	MBROLA based American English male voice for festival

DEPENDS+=	festival>=1.4.0:../festival
DEPENDS+=	festlex-poslex>=1.4.0:../festlex-poslex
DEPENDS+=	festlex-cmu>=1.4.0:../festlex-cmu
DEPENDS+=	mbrola-301h:../mbrola
DEPENDS+=	mbrolavox-us3-990208:../mbrolavox-us3

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us3_mbrola

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us3 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us3/us3mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
