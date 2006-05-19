# $NetBSD: Makefile,v 1.19 2006/05/19 16:18:52 rillig Exp $

DISTNAME=	festvox_en1
PKGNAME=	festvox-en1-1.4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html
COMMENT=	MBROLA based British English male voice for festival

DEPENDS+=	festival>=1.4.0:../../audio/festival
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festlex-oald>=1.4.0:../../audio/festlex-oald
DEPENDS+=	mbrola-301hnb1:../../audio/mbrola
DEPENDS+=	mbrolavox-en1-980910nb1:../../audio/mbrolavox-en1

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/en1_mbrola

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}
#ugh
	${LN} -fs ../../../../../mbrola/voices/en1 ${MBROLA}
	${LN} -fs ../../../../../mbrola/voices/en1/en1mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
