# $NetBSD: Makefile,v 1.13 2001/07/14 12:37:51 jlam Exp $

DISTNAME=	voice_ogirab_di-2.0
PKGNAME=	festvox-ogirab-2.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts
COMMENT=	British English male voice for the festival speech synthesis system

DEPENDS+=	festival-1.4.0:../festival
DEPENDS+=	festlex-ogi-2.0:../festlex-ogi

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type d -name CVS -print | ${XARGS} ${RM} -fr

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
