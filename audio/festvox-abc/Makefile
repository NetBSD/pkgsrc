# $NetBSD: Makefile,v 1.17 2004/01/27 00:53:12 heinz Exp $

DISTNAME=	voice_abc_di-2.0
PKGNAME=	festvox-abc-2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Mexican Spanish male voice for the festival speech synthesis system

DEPENDS+=	festival>=1.4.0:../festival
DEPENDS+=	festlex-ogi>=2.0:../festlex-ogi
DEPENDS+=	festogi-spanish>=2.0:../festogi-spanish

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${RM} -f ${WRKSRC}/lib/voices/spanish/abc_diphone/group/hvslpcOGI16k.group
	${FIND} ${WRKSRC} -type d -name CVS -print | ${XARGS} ${RM} -fr

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}

.include "../../mk/bsd.pkg.mk"
