# $NetBSD: Makefile,v 1.8 2001/07/14 12:37:51 jlam Exp $

DISTNAME=	festvox_us1
PKGNAME=	festvox-us1-1.4.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.0/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	MBROLA based American English female voice for festival

DEPENDS+=	festival-1.4.0:../festival
DEPENDS+=	festlex-poslex-1.4.0:../festlex-poslex
DEPENDS+=	festlex-cmu-1.4.0:../festlex-cmu
DEPENDS+=	mbrola-301h:../mbrola
DEPENDS+=	mbrolavox-us1-980512:../mbrolavox-us1

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us1_mbrola

ONLY_FOR_PLATFORM=      NetBSD-*-i386

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us1 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us1/us1mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
