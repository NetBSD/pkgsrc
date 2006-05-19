# $NetBSD: Makefile,v 1.14 2006/05/19 16:18:52 rillig Exp $

DISTNAME=	festvox_us1
PKGNAME=	festvox-us1-1.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	MBROLA based American English female voice for festival

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festlex-cmu>=1.4.0:../../audio/festlex-cmu
DEPENDS+=	mbrola-301hnb1:../../audio/mbrola
DEPENDS+=	mbrolavox-us1-980512nb1:../../audio/mbrolavox-us1

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/us1_mbrola

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/us1 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/us1/us1mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
