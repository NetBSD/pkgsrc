# $NetBSD: Makefile,v 1.6 1999/10/27 17:14:01 agc Exp $

DISTNAME=	festvox-abc-2.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	voice_abc_di-2.0.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts

BROKEN=		broken PLIST

DEPENDS+=	festival-1.4.0:../festival \
		festlex-ogi-2.0:../festlex-ogi \
		festogi-spanish-2.0:../festogi-spanish

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755
	@ ${RM} -f ${WRKSRC}/lib/voices/spanish/abc_diphone/group/hvslpcOGI16k.group

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
