# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:34:43 proff Exp $

DISTNAME=	festvox-jph-1.4
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	voice_jph-1.4.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts

DEPENDS+=	festival-1.3.1:../festival \
		festlex-ogi-1.4:../festlex-ogi

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
