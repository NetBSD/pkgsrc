# $NetBSD: Makefile,v 1.14 2004/01/20 12:07:41 agc Exp $

DISTNAME=	OGIlexicon-2.0
PKGNAME=	festlex-ogi-2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://cslu.cse.ogi.edu/pub/tts/

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://cslu.cse.ogi.edu/tts/
COMMENT=	Composite pronounciation dictionary from ogi.edu for festival

DEPENDS+=	festival>=1.4.0:../festival
DEPENDS+=	festlex-poslex>=1.4.0:../festlex-poslex

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/festival
NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}
	cd ${WRKSRC} && ${PAX} -rw * ${FHOME}

.include "../../mk/bsd.pkg.mk"
