# $NetBSD: Makefile,v 1.12 2001/05/19 03:56:27 jlam Exp $

DISTNAME=	voice_hvs_di-2.0
PKGNAME=	festvox-hvs-2.0
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts
COMMENT=	Mexican Spanish female voice for the festival

DEPENDS+=	festival-1.4.0:../festival
DEPENDS+=	festlex-ogi-2.0:../festlex-ogi
DEPENDS+=	festogi-spanish-2.0:../festogi-spanish

LICENSE=	no-commercial-use

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -r -w * ${FHOME}

.include "../../mk/bsd.pkg.mk"
