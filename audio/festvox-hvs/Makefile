# $NetBSD: Makefile,v 1.7 1999/10/28 01:23:53 hubertf Exp $

DISTNAME=	festvox-hvs-2.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/
DISTFILES=	voice_hvs_di-2.0.tar.gz

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
	find ${WRKSRC} -type d -print0 | xargs -0 chmod 755
	find ${WRKSRC} -type d -name CVS | xargs rm -fr

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && pax -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
