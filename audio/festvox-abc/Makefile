# $NetBSD: Makefile,v 1.8 1999/12/25 22:38:57 wiz Exp $

DISTNAME=	voice_abc_di-2.0
PKGNAME=	festvox-abc-2.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts

DEPENDS+=	festival-1.4.0:../festival \
		festlex-ogi-2.0:../festlex-ogi \
		festogi-spanish-2.0:../festogi-spanish

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	${RM} -f ${WRKSRC}/lib/voices/spanish/abc_diphone/group/hvslpcOGI16k.group
	find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
